/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:43:23 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/21 15:11:41 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static volatile t_sig	g_sig_s;

void	init_all(struct sigaction *sa)
{
	int	i;

	if (sa != NULL)
	{
		sigemptyset(&(sa->sa_mask));
		sa->sa_handler = NULL;
		sa->sa_flags = SA_SIGINFO;
		sigaddset(&(sa->sa_mask), SIGUSR1);
		sigaddset(&(sa->sa_mask), SIGUSR2);
		g_sig_s.bit = -1;
		g_sig_s.pid = -1;
	}
	g_sig_s.printable.bits_num = 8;
	g_sig_s.printable.c = 0;
	g_sig_s.printable.uni_idx = 0;
	g_sig_s.printable.uni_byte = 0;
	g_sig_s.printable.zero_flag = 0;
	i = 0;
	while (i < 4)
	{
		g_sig_s.printable.uni_c[i] = 0;
		i++;
	}
}

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (g_sig_s.pid == -1)
	{
		g_sig_s.pid = info->si_pid;
		kill(info->si_pid, SIGUSR1);
	}
	else if (g_sig_s.pid != info->si_pid)
	{
		if (g_sig_s.bit != -1)
			kill(info->si_pid, SIGUSR2);
		else
		{
			g_sig_s.pid = info->si_pid;
			kill(info->si_pid, SIGUSR1);
		}
	}
	else
	{
		if (signo == SIGUSR1)
			g_sig_s.bit = 0;
		else if (signo == SIGUSR2)
			g_sig_s.bit = 1;
	}
}

void	print_char(int idx)
{
	char	print[4];
	int		i;

	if (idx == (g_sig_s.printable.uni_byte - 1))
	{
		i = 0;
		while (i <= idx)
		{
			print[i] = g_sig_s.printable.uni_c[i];
			i++;
		}
		write(1, print, g_sig_s.printable.uni_byte);
		if (print[0] == '\0')
			kill(g_sig_s.pid, SIGUSR1);
		init_all(NULL);
	}
	else
		g_sig_s.printable.uni_idx++;
	g_sig_s.printable.bits_num = 8;
}

void	print_text(void)
{
	int		idx;

	idx = g_sig_s.printable.uni_idx;
	(g_sig_s.printable.bits_num)--;
	if (g_sig_s.bit == 0)
	{
		if (idx == 0 && g_sig_s.printable.uni_byte == 0)
			g_sig_s.printable.uni_byte = 1;
		g_sig_s.printable.zero_flag = 1;
	}
	else if (g_sig_s.bit == 1)
	{
		if (idx == 0 && g_sig_s.printable.zero_flag == 0)
			(g_sig_s.printable.uni_byte)++;
		g_sig_s.printable.uni_c[idx] += (1 << g_sig_s.printable.bits_num);
	}
	if (g_sig_s.printable.bits_num == 0)
		print_char(idx);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	init_all(&sa);
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_sig_s.bit != -1)
		{
			print_text();
			g_sig_s.bit = -1;
		}
	}
	exit(0);
}
