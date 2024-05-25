/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:39:27 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/21 14:43:34 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static volatile t_sig	g_sig_s;

void	init_all(struct sigaction *sa)
{
	sigemptyset(&(sa->sa_mask));
	sa->sa_handler = NULL;
	sa->sa_flags = SA_SIGINFO;
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	g_sig_s.bit = -1;
	g_sig_s.pid = -1;
	g_sig_s.printable.bits_num = 8;
	g_sig_s.printable.c = 0;
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

void	print_text(void)
{
	char	print;

	(g_sig_s.printable.bits_num)--;
	if (g_sig_s.bit == 0)
		g_sig_s.printable.c += (0 * pow_2(g_sig_s.printable.bits_num));
	else if (g_sig_s.bit == 1)
		g_sig_s.printable.c += (1 * pow_2(g_sig_s.printable.bits_num));
	if (g_sig_s.printable.bits_num == 0)
	{
		print = g_sig_s.printable.c;
		write(1, &print, 1);
		g_sig_s.printable.bits_num = 8;
		if (g_sig_s.printable.c == '\0')
			kill(g_sig_s.pid, SIGUSR1);
		g_sig_s.printable.c = 0;
	}
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
