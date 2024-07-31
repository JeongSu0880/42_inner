/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:24:07 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/29 15:57:01 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	hold_both_fork(t_philo *philo)
{
	int	r_done;
	int	l_done;

	r_done = 0;
	l_done = 0;
	if (philo->num_ate != 0 && \
		ft_gettime() - philo->last_eat + philo->eat <= philo->starve)
		return (0);
	if (hold_fork_right(philo) == 1)
		r_done = 1;
	if (hold_fork_left(philo) == 1)
		l_done = 1;
	if (r_done == 1 && l_done == 1)
		return (print_hold_fork(philo));
	if (r_done)
		put_fork_down_right(philo);
	if (l_done)
		put_fork_down_left(philo);
	return (FALSE);
}

int	philo_die(t_philo *philo, int *dead_flag, int print_flag)
{
	pthread_mutex_lock(&(philo->share->dead->mutex));
	if (*dead_flag == 1)
	{
		pthread_mutex_unlock(&(philo->share->dead->mutex));
		return (DEAD_RETURN);
	}
	*dead_flag = 1;
	pthread_mutex_unlock(&(philo->share->dead->mutex));
	if (print_flag == 1)
	{
		pthread_mutex_lock(&(philo->share->print_mutex));
		printf("%zu %d died\n", ft_gettime() - philo->birth, philo->id);
		pthread_mutex_unlock(&(philo->share->print_mutex));
	}
	return (DEAD_RETURN);
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->print_mutex));
	if (check_is_dead(philo->share->dead))
	{
		pthread_mutex_unlock(&(philo->share->print_mutex));
		return (DEAD_RETURN);
	}
	printf("%zu %d is sleeping\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (ft_usleep(philo->sleep, philo));
}

int	philo_eat(t_philo *philo)
{
	while (1)
	{
		if (is_philo_terminated(philo) == TRUE)
			return (DEAD_RETURN);
		if (hold_both_fork(philo) == TRUE)
		{
			if (print_eat(philo) == DEAD_RETURN)
				return (DEAD_RETURN);
			if (ft_usleep(philo->eat, philo) == DEAD_RETURN)
				return (DEAD_RETURN);
			put_fork_down_right(philo);
			put_fork_down_left(philo);
			if (philo->num_ate + 1 == philo->num_must_eat)
				return (DONE_EAT);
			return (philo_sleep(philo));
		}
		else
			usleep(50);
	}
	return (0);
}

int	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->print_mutex));
	if (check_is_dead(philo->share->dead))
	{
		pthread_mutex_unlock(&(philo->share->print_mutex));
		return (DEAD_RETURN);
	}
	printf("%zu %d is thinking\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (0);
}
