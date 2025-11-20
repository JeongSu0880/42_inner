/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_and_init_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:15:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:28:54 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_one_philo(t_philo *philo, t_share *share)
{
	philo->eat = share->time_to_eat;
	philo->sleep = share->time_to_sleep;
	philo->starve = share->time_to_die;
	philo->num_ate = 0;
	if (share->num_flag == 1)
	{
		philo->num_flag = 1;
		philo->num_must_eat = share->num_of_eat;
	}
	philo->l_fork = &(share->fork[philo->id - 1]);
	if (philo->id == 1)
		philo->r_fork = &(share->fork[share->num_of_philo - 1]);
	else
		philo->r_fork = &(share->fork[philo->id - 2]);
}

static int	init_all_mutex(t_share *share)
{
	if (pthread_mutex_init(&share->dead->mutex, NULL) != 0)
		return (ERROR_RETURN);
	if (pthread_mutex_init(&share->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&share->dead->mutex);
		return (ERROR_RETURN);
	}
	return (0);
}

int	init_all(t_share *share, t_philo **philo)
{
	int	i;

	i = 0;
	share->fork = (t_fork *)malloc(sizeof(t_fork) * share->num_of_philo);
	*philo = (t_philo *)malloc(sizeof(t_philo) * share->num_of_philo);
	share->dead = (t_dead *)malloc(sizeof(t_dead));
	share->dead->is_dead = 0;
	if ((share->fork == NULL || philo == NULL) && share->num_of_philo != 0)
		return (ERROR_RETURN);
	while (i < share->num_of_philo)
	{
		pthread_mutex_init(&share->fork[i].mutex, NULL);
		share->fork[i].is_occupied = 0;
		share->fork[i].reach = 0;
		(*philo)[i].share = share;
		(*philo)[i].id = i + 1;
		init_one_philo(&((*philo)[i]), share);
		i++;
	}
	if (init_all_mutex(share) == ERROR_RETURN)
		return (ERROR_RETURN);
	return (0);
}
