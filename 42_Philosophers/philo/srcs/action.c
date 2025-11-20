/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:05:37 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:18:34 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	hold_fork_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	if (philo->r_fork->is_occupied == 0)
	{
		philo->r_fork->is_occupied = 1;
		pthread_mutex_unlock(&(philo->r_fork->mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->r_fork->mutex);
	return (FALSE);
}

int	hold_fork_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mutex);
	if (philo->l_fork->is_occupied == 0)
	{
		philo->l_fork->is_occupied = 1;
		pthread_mutex_unlock(&(philo->l_fork->mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->l_fork->mutex);
	return (FALSE);
}

void	put_fork_down_right(t_philo *philo)
{
	pthread_mutex_lock(&(philo->r_fork->mutex));
	philo->r_fork->is_occupied = 0;
	pthread_mutex_unlock(&(philo->r_fork->mutex));
}

void	put_fork_down_left(t_philo *philo)
{
	pthread_mutex_lock(&(philo->l_fork->mutex));
	philo->l_fork->is_occupied = 0;
	pthread_mutex_unlock(&(philo->l_fork->mutex));
}
