/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/19 16:39:58 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_philo_terminated(t_philo *philo, int *not_eat)
{
	if (*not_eat >= philo->starve)
	{
		philo_die(philo, &(philo->share->dead.is_dead));
		return (1);
	}
	if (philo->share->dead.is_dead == 1)
		return (1);
	return (0);
}

int	ft_usleep(int ms, t_philo *philo, int *not_eat)
{
	size_t	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (is_philo_terminated(philo, not_eat))
			break ;
		usleep(250);
		*not_eat = ft_gettime() - start;
	}
	return (0);
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
