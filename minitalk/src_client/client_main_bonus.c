/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:39:03 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/21 14:42:20 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static volatile t_sig_c	g_sig;

void	send_per_bit(char c, pid_t serv)
{
	int		num;
	char	bit_moved;

	num = 8;
	while (num > 0)
	{
		bit_moved = c >> 7;
		if ((bit_moved ^ 0) == 0)
		{
			if (kill(serv, SIGUSR1) == -1)
				handle_error("Error\n");
		}
		else
		{
			if (kill(serv, SIGUSR2) == -1)
				handle_error("Error\n");
		}
		num--;
		c = c << 1;
		usleep(SLEEP);
	}
}

void	check_sig(int signo)
{
	if (signo == SIGUSR1)
		g_sig.usr1++;
	if (signo == SIGUSR2)
		g_sig.usr2 = 1;
}

void	loop_and_send(int serv_pid, char *argv[], int *i)
{
	if (g_sig.usr1 != -1)
	{
		send_per_bit(argv[2][*i], serv_pid);
		if (argv[2][*i] != '\0')
			(*i)++;
	}
	if (g_sig.usr1 == 1)
	{
		ft_printf("print all\n");
		exit(0);
	}
	if (g_sig.usr2 != -1)
	{
		g_sig.usr2 = -1;
		sleep(3);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	serv_pid;
	int		i;

	if (argc < 2)
		exit(0);
	if (argv[2] == NULL || argv[2][0] == '\0')
		exit(0);
	i = 0;
	g_sig.usr1 = -1;
	g_sig.usr2 = -1;
	serv_pid = ft_atoi(argv[1]);
	if (kill(serv_pid, SIGUSR1) == -1)
		handle_error("Error\n");
	signal(SIGUSR1, check_sig);
	signal(SIGUSR2, check_sig);
	while (1)
	{
		usleep(30);
		loop_and_send(serv_pid, argv, &i);
	}
	exit(0);
}
