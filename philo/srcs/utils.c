/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/23 19:46:29 by jungslee         ###   ########.fr       */
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
	// dprintf(2, "is dead flag what ::::::: %d\n", dead->is_dead);
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
		// dprintf(2, "%d -> check_and_die!!!!\n", philo->id);
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
		{
			// dprintf(2, "usleep\n");//TODO 지워
			return (-1);
		}
		usleep(250);
	}
	return (1);
}

// int	ft_usleep_thinking(t_philo *philo, int *not_eat)
// {
// 	int	start;
// 	int	can_eat;

// 	start = ft_gettime();
// 	can_eat = 0;
// 	while (1)
// 	{
// 		if (is_philo_terminated(philo, not_eat))
// 			break ;
// 		if (check_fork_stat(philo->l_fork, philo->r_fork))//TODO 뮤텍스
// 		{
// 			can_eat = hold_both_fork(philo);
// 			if (can_eat == 1)// 여기에 가장 오래 굶은 철학자가 먼저 먹게 하는 조건 추가.			
// 				return (1);
// 		}
// 		usleep(250);
// 		*not_eat = ft_gettime() - start;
// 	}
// 	return (0);
// }
