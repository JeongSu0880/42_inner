/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_and_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:06:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/12 17:10:37 by jungslee         ###   ########.fr       */
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

static void	init_input(int num, int i, t_state *state)
{
	if (i == 1)
		state->num_of_philo = num;
	else if (i == 2)
		state->time_to_die = num;
	else if (i == 3)
		state->time_to_eat = num;
	else if (i == 4)
		state->time_to_sleep = num;
	else if (i == 5)
	{
		state->num_flag = 1;
		state->num_of_eat = num;
	}
}

int	check_argument_validity_and_init_input(int argc, char *argv[], \
											t_state *state)
{
	int	i;
	int	num;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (-1);
	state->num_flag = -1;
	while (i < argc)
	{
		num = ft_atoi_check_int(argv[i]);
		if (num == -1)
			return (-1);
		init_input(num, i, state);
		i++;
	}
	return (0);
}

int	init_all(t_state *state, t_philo **philo)
{
	int	i;

	i = 0;
	state->fork = (t_fork *)malloc(sizeof(t_fork) * state->num_of_philo);
	*philo = (t_philo *)malloc(sizeof(t_philo) * state->num_of_philo);
	if ((state->fork == NULL || philo == NULL) && state->num_of_philo != 0)
		return (-1);
	while (i < state->num_of_philo)
	{
		pthread_mutex_init(&state->fork[i].mutex, NULL);
		state->fork[i].fork_stat = 0;
		(*philo)[i].id = i;
		(*philo)[i].eat = state->time_to_eat;
		(*philo)[i].sleep = state->time_to_sleep;
		(*philo)[i].die = state->time_to_die;
		(*philo)[i].num_eat = 0;
		i++;
	}
	pthread_mutex_init(&state->dead.mutex, NULL);
	return (0);
}
