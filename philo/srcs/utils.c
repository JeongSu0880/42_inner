/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/16 21:15:24 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	is_philo_terminated(t_philo *philo)
// {
	
// }

int	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t ms, t_philo *philo)
{
	size_t	start;
	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		// if (is_philo_terminated(philo))
		// 	break ;
		usleep(250);
	}
	return (0);
}
