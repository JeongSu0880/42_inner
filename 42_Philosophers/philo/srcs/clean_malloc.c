/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:09:26 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/26 12:59:09 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philo, t_share *share)
{
	free(philo);
	free(share->fork);
	free(share->dead);
	free(share);
}

void	destroy_all_mutex(t_share *share)
{
	int	i;

	i = 0;
	while (i < share->num_of_philo)
	{
		pthread_mutex_destroy(&share->fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&share->dead->mutex);
	pthread_mutex_destroy(&share->print_mutex);
}

void	wait_thread_end(t_philo *philo, t_share *share)
{
	int	i;

	i = 0;
	while (i < share->num_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
