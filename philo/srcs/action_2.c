/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:31:18 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 10:01:32 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_fork_stat(t_fork *l_fork, t_fork *r_fork)
{
	pthread_mutex_lock(&l_fork->mutex);
	pthread_mutex_lock(&r_fork->mutex);
	// dprintf(2, "aera\n");
	// dprintf(2, "fork stat l :: %d  r :: %d\n", l_fork->is_occupied, r_fork->is_occupied);
	if (l_fork->is_occupied == 0 && r_fork->is_occupied == 0)
	{
		// dprintf(2, "fork stat 0\n");
		pthread_mutex_unlock(&l_fork->mutex);
		pthread_mutex_unlock(&r_fork->mutex);
		return (1);
	}
	pthread_mutex_unlock(&l_fork->mutex);
	pthread_mutex_unlock(&r_fork->mutex);
	return (0);
}

int	check_reach_done(t_fork *l_fork, t_fork *r_fork)
{
	pthread_mutex_lock(&l_fork->mutex);
	pthread_mutex_lock(&r_fork->mutex);
	if (l_fork->reach == 1 && r_fork->reach == 1)
	{
		pthread_mutex_unlock(&l_fork->mutex);
		pthread_mutex_unlock(&r_fork->mutex);
		return (1);
	}
	pthread_mutex_unlock(&l_fork->mutex);
	pthread_mutex_unlock(&r_fork->mutex);
	return (0);
}