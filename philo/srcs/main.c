/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:04:52 by jungslee         ###   ########.fr       */
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
		ft_gettime() - philo->last_eat + philo->eat < philo->starve)
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
		if (hold_both_fork(philo))
		{
			pthread_mutex_lock(&(philo->share->print_mutex));
			if (check_is_dead(philo->share->dead) == TRUE)
			{
				pthread_mutex_unlock(&(philo->share->print_mutex));
				return (DEAD_RETURN);
			}
			printf("%zu %d is eating\n", ft_gettime() - philo->birth, philo->id);
			pthread_mutex_unlock(&(philo->share->print_mutex));
			philo->last_eat = ft_gettime();
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
	// if (is_philo_terminated(philo) == 1)
	// 	return (-1);
	pthread_mutex_lock(&(philo->share->print_mutex));
	if (check_is_dead(philo->share->dead))
	{
		pthread_mutex_unlock(&(philo->share->print_mutex));
		return (-1);
	}
	printf("%zu %d is thinking\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (0);
}

void	*philo_behave(void *philo)
{
	t_philo	*me;
	t_share *share;
	int		eat_status;

	me = (t_philo *)philo;
	share = me->share;
	me->last_eat = me->birth;
	while (1)
	{
		if (me->num_flag == 1 && me->num_ate == me->num_must_eat)
			return (0);
		if (is_philo_terminated(philo) == 1)
			return (0);
		eat_status = philo_eat(philo);
		if (eat_status == -1 || eat_status == 1)
			return (0);
		me->num_ate++;
		if (philo_think(philo) == -1)
			return (0);
	}
	return (0);
}

int	start_all_thread(t_philo *philo, t_share *share)
{
	int	i;

	i = 0;
	size_t time;
	time = ft_gettime();
	while (i < share->num_of_philo)
	{
 		philo[i].birth = time;
		if (pthread_create(&(philo[i].thread), NULL, philo_behave, (void *)&(philo[i])) < 0)
			return (handle_error("pthread_create error", share));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_share		*share;
	t_philo		*philo;
	int			i;

	share = (t_share *)malloc(sizeof(t_share));
	memset(share, 0, sizeof(t_share));
	philo = NULL;
	if (check_argument_validity_and_init_input(argc, argv, share) == -1)
		return (argument_error_return());
	if (init_all(share, &philo) == ERROR_RETURN || \
		start_all_thread(philo, share) == ERROR_RETURN)
	{
		free_all(philo, share);
		destroy_all_mutex(share);
		return (ERROR_RETURN);
	}
	i = 0;
	while (i < share->num_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

//지연 줄이기 ->> 3 610     200 100 했했을  때  잘 되어야함.
// 먹는 횟수 넣었을 때 끝날 때 왜 죄다 띵킹???? 이상행동 이상행동
//자원 분배
// 할당한 것들 다 프리 시켜주기