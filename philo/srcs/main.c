/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/22 22:47:17 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	print_philo(t_philo *philo, int num)//지워라
// {
// 	for (int i = 0; i < num; i++)
// 	{
// 		printf("---------------------------------\n");
// 		printf("philo id : %d\n", philo[i].id);
// 		printf("philo eat : %d\n", philo[i].eat);
// 		printf("philo sleep : %d\n", philo[i].sleep);
// 		printf("philo die : %d\n", philo[i].starve);
// 		printf("philo num_eat : %d\n", philo[i].num_eat);
// 		printf("---------------------------------\n");
// 	}
// }

int	hold_both_fork_even(t_philo *philo)
{
	int	r_done;
	int	l_done;

	r_done = 0;
	l_done = 0;
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
	else if (r_done == 1)
		put_fork_down_right(philo);
	else if (l_done == 1)
		put_fork_down_left(philo);
	return (0);
}

int	hold_both_fork_odd(t_philo *philo)
{
	int	r_done;
	int	l_done;

	r_done = 0;
	l_done = 0;
	if (hold_fork_left(philo) == 1)
		l_done = 1;
	if (hold_fork_right(philo) == 1)
		r_done = 1;
	if (r_done == 1 && l_done == 1)
	{
		pthread_mutex_lock(&philo->share->print_mutex);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		pthread_mutex_unlock(&philo->share->print_mutex);
		return (1);
	}
	else if (l_done == 1)
		put_fork_down_left(philo);
	else if (r_done == 1)
		put_fork_down_right(philo);
	return (0);
}

int	philo_die(t_philo *philo, int *dead_flag, int print_flag)
{
	pthread_mutex_lock(&(philo->share->dead.mutex));
	*dead_flag = 1;//TODO 이렇게 해도 바뀌나??
	pthread_mutex_unlock(&(philo->share->dead.mutex));
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
	size_t	start;

	if (is_philo_terminated(philo) == 1)
	{
		dprintf(2, "philo_sleep\n");//TODO 지워
		return (-1);
	}
	// if ((ft_gettime() - philo->last_eat + philo->sleep) >= philo->starve)
	// 	return (philo_die(philo, &(philo->share->dead.is_dead), 1));
	pthread_mutex_lock(&(philo->share->print_mutex));
	start = ft_gettime();//TODO 이부분 어떡하지
	printf("%zu %d is sleeping\n", start - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (ft_usleep(philo->sleep, philo));
}

int	philo_eat(t_philo *philo)
{
	size_t		start;
	int			hold;

	if (is_philo_terminated(philo) == 1)
	{
		dprintf(2, "philo_eat\n");//TODO 지워
		return (-1);
	}
	if (philo->id & 1)
		hold = hold_both_fork_even(philo);
	else
		hold = hold_both_fork_odd(philo);
	if (hold)
	{
		pthread_mutex_lock(&(philo->share->print_mutex));
		start = ft_gettime();
		printf("%zu %d is eating\n", start - philo->birth, philo->id);
		pthread_mutex_unlock(&(philo->share->print_mutex));
		philo->last_eat = start;
		ft_usleep(philo->eat, philo);
		put_fork_down_right(philo);
		put_fork_down_left(philo);
		philo->num_eat++;
		// philo_sleep(philo);
		return (philo_sleep(philo));
	}
	return (0);
}

int	philo_think(t_philo *philo)
{
	size_t		start;

	if (is_philo_terminated(philo) == 1)
	{
		dprintf(2, "philo_think\n");//TODO 지워
		return (-1);
	}
	pthread_mutex_lock(&(philo->share->print_mutex));
	start = ft_gettime();
	printf("%zu %d is thinking\n", start - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (0);
}

void	*philo_behave(void *philo)
{
	t_philo	*me;
	t_share *share;
	int		pre_behave;

	me = (t_philo *)philo;
	share = me->share;
	me->birth = ft_gettime();
	me->last_eat = me->birth;
	while (1)
	{
		if (share->num_flag == 1 && me->num_eat == share->num_of_eat)
			return (0);
		if (is_philo_terminated(philo) == 1)
		{
			dprintf(2, "philo_behave\n");//TODO 지워
			return (0);
		}
		pre_behave = philo_eat(philo);
		dprintf(2, "eat, sleep pre_behave %d\n", pre_behave);
		if (pre_behave == -1)
			return (0);
		if (pre_behave == 1)
			pre_behave = philo_think(philo);
		dprintf(2, "think pre_behave %d\n", pre_behave);
		if (pre_behave == -1)
			return (0);
	}
	return (0);
}

int	start_all_thread(t_philo *philo, t_share *share)
{
	int	i;

	i = 0;
	while (i < share->num_of_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_behave, (void *)&(philo[i])) < 0)
			return (handle_error("pthread_create error", share));
		i++;
	}
	return (0);
}

// void	*monitor_behave(void *arg)
// {
// 	t_philo *philo;
// 	int		num_philo;
// 	int		i;

// 	philo = (t_philo *)arg;
// 	num_philo = philo[0].share->num_of_philo;
// 	//모니터링 스레드 생성
// 		// 하는 역할 = 죽은 철학자가 있는지 체크
// 		// 횟횟수만큰 먹었는지 체크
// 		// ㅇㅔ러 발발생생했했으면 끝내기
// 	i = 0;
// 	while (i < num_philo)
// 	{
// 		pthread_join(philo[i].thread, NULL);
// 		i++;
// 	}
// 	return (0);
// }

// int	start_monitoring(pthread_t *monitor, t_share *share, t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	if (pthread_create(monitor, NULL, monitor_behave, (void *)philo) != 0)
// 		return (handle_error("pthread_create error", share));
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_share		share;
	t_philo		*philo;
	pthread_t	monitor;
	int			result;
	int			i;

	memset(&share, 0, sizeof(t_share));
	philo = NULL;
	i = 0;
	if (check_argument_validity_and_init_input(argc, argv, &share) == -1)
		return (argument_error_return());
	if (init_all(&share, &philo) == -1)
		return (0);
	// start_monitoring(&monitor, &share, philo);
	if (start_all_thread(philo, &share) == -1)
		return (-1);// TODO 다정리!!!
	while (i < share.num_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&share.dead.mutex);
	pthread_mutex_destroy(&share.print_mutex);
	pthread_mutex_destroy(&share.error.mutex);//TODO 이거 넣어 말아.ㅡㅁ
	while (i < share.num_of_philo)
	{
		pthread_mutex_destroy(&share.fork[i].mutex);
		pthread_detach(philo[i].thread);
		i++;
	}
}



// 에러 처리 함수 정리하기.. 하나로...
// die 한번만 프린트 하기
// 마지막 스레드 정리, 다 프리해주기