/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 17:25:50 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	hold_both_fork_even(t_philo *philo)
// {
// 	int	r_done;
// 	int	l_done;

// 	r_done = 0;
// 	l_done = 0;
// 	// while (r_done == 1 && l_done == 1)
// 	if (hold_fork_right(philo) == 1)
// 		r_done = 1;
// 	if (hold_fork_left(philo) == 1)
// 		l_done = 1;
// 	if (r_done == 1 && l_done == 1)
// 	{
// 		pthread_mutex_lock(&philo->share->print_mutex);
// 		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
// 		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
// 		pthread_mutex_unlock(&philo->share->print_mutex);
// 		return (1);
// 	}
// 	else if (r_done == 1)
// 		put_fork_down_right(philo);
// 	else if (l_done == 1)
// 		put_fork_down_left(philo);
// 	return (0);
// }

// int	hold_both_fork_odd(t_philo *philo)
// {
// 	int	r_done;
// 	int	l_done;

// 	r_done = 0;
// 	l_done = 0;

// 	if (hold_fork_left(philo) == 1)
// 		l_done = 1;
// 	if (hold_fork_right(philo) == 1)
// 		r_done = 1;
// 	if (r_done == 1 && l_done == 1)
// 	{
// 		pthread_mutex_lock(&philo->share->print_mutex);
// 		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
// 		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
// 		pthread_mutex_unlock(&philo->share->print_mutex);
// 		return (1);
// 	}
// 	else if (l_done == 1)
// 		put_fork_down_left(philo);
// 	else if (r_done == 1)
// 		put_fork_down_right(philo);
// 	return (0);
// }

void wait_wait(void)
{
	int	i;

	i = 0;
	while (i < 100)
		i++;
}



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
	{
		pthread_mutex_lock(&philo->share->print_mutex);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		pthread_mutex_unlock(&philo->share->print_mutex);
		return (1);
	}
	if (r_done)
		put_fork_down_right(philo);
	if (l_done)
		put_fork_down_left(philo);
	return (0);
}

int	philo_die(t_philo *philo, int *dead_flag, int print_flag)
{
	pthread_mutex_lock(&(philo->share->dead->mutex));
	if (*dead_flag == 1)
	{
		pthread_mutex_unlock(&(philo->share->dead->mutex));
		return (-1);
	}
	*dead_flag = 1;//TODO 이렇게 해도 바뀌나??
	pthread_mutex_unlock(&(philo->share->dead->mutex));
	if (print_flag == 1)
	{
		pthread_mutex_lock(&(philo->share->print_mutex));
		printf("%zu %d died\n", ft_gettime() - philo->birth, philo->id);
		pthread_mutex_unlock(&(philo->share->print_mutex));
	}
	return (-1);
}

int	philo_sleep(t_philo *philo)
{
	int	ret;

	if (is_philo_terminated(philo) == 1)
		return (-1);
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%zu %d is sleeping\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	ret = ft_usleep(philo->sleep, philo);
	return (ret);
}

int	philo_eat(t_philo *philo)
{
	size_t		start;
	int			hold;
	int			ret;

	while (1)
	{
		if (is_philo_terminated(philo) == 1)
			return (-1);
		if (hold_both_fork(philo))
		{
			pthread_mutex_lock(&(philo->share->print_mutex));
			printf("%zu %d is eating\n", ft_gettime() - philo->birth, philo->id);
			pthread_mutex_unlock(&(philo->share->print_mutex));
			philo->last_eat = ft_gettime();
			if (ft_usleep(philo->eat, philo) == -1)
				return (-1);
			put_fork_down_right(philo);
			put_fork_down_left(philo);
			ret = philo_sleep(philo);
			return (ret);
		}
		else
			usleep(50);
	}
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (is_philo_terminated(philo) == 1)
		return (-1);
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%zu %d is thinking\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (0);
}

void	*philo_behave(void *philo)
{
	t_philo	*me;
	t_share *share;

	me = (t_philo *)philo;
	share = me->share;
	me->last_eat = me->birth;
	while (1)
	{
		if (me->num_flag == 1 && me->num_ate == me->num_must_eat)
			return (0);
		if (is_philo_terminated(philo) == 1)
			return (0);
		if (philo_eat(philo) == -1)
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
	if (init_all(share, &philo) == -1)
		return (0);
	if (start_all_thread(philo, share) == -1)
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