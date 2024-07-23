/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/23 20:46:52 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_is_dead(t_dead *dead)
{
	pthread_mutex_lock(&dead->mutex);
	if (dead->is_dead == 1)
	{
		pthread_mutex_unlock(&dead->mutex);
		return (1);
	}
	pthread_mutex_unlock(&dead->mutex);
	return (0);
}

int	is_philo_terminated(t_philo *philo)
{
	if (check_is_dead(philo->share->dead))
	{
		philo_die(philo, &(philo->share->dead->is_dead), 0);
		return (1);
	}
	if (ft_gettime() - philo->last_eat > philo->starve)
	{
		philo_die(philo, &(philo->share->dead->is_dead), 1);
		return (1);
	}
	return (0);
}

int	ft_usleep(int ms, t_philo *philo)
{
	size_t	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (is_philo_terminated(philo))
			return (-1);
		usleep(100);
	}
	return (1);
}
