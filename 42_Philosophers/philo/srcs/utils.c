/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:26:56 by jungslee         ###   ########.fr       */
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
		return (TRUE);
	}
	pthread_mutex_unlock(&dead->mutex);
	return (FALSE);
}

int	is_philo_terminated(t_philo *philo)
{
	if (check_is_dead(philo->share->dead))
	{
		philo_die(philo, &(philo->share->dead->is_dead), 0);
		return (TRUE);
	}
	if (ft_gettime() - philo->last_eat > philo->starve)
	{
		philo_die(philo, &(philo->share->dead->is_dead), 1);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_usleep(size_t ms, t_philo *philo)
{
	size_t	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (is_philo_terminated(philo))
			return (DEAD_RETURN);
		usleep(200);
	}
	return (0);
}
