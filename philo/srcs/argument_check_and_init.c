/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_and_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:06:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 18:15:27 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_atoi_check_int(char *str)
{
	long long	num;

	num = 0;
	while (str != NULL && *str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (-1);
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num < 0 || num > 2147483647)
		return (-1);
	return ((int)num);
}

static void	init_input(int num, int i, t_share *share)
{
	if (i == 1)
		share->num_of_philo = num;
	else if (i == 2)
		share->time_to_die = num;
	else if (i == 3)
		share->time_to_eat = num;
	else if (i == 4)
		share->time_to_sleep = num;
	else if (i == 5)
	{
		share->num_flag = 1;
		share->num_of_eat = num;
	}
}

int	check_argument_validity_and_init_input(int argc, char *argv[], \
											t_share *share)
{
	int	i;
	int	num;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (-1);
	share->num_flag = -1;
	while (i < argc)
	{
		num = ft_atoi_check_int(argv[i]);
		if (num == -1)
			return (-1);
		init_input(num, i, share);
		i++;
	}
	return (0);
}
