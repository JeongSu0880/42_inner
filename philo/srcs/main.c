/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/19 22:55:10 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo(t_philo *philo, int num)//지워라
{
	for (int i = 0; i < num; i++)
	{
		printf("---------------------------------\n");
		printf("philo id : %d\n", philo[i].id);
		printf("philo eat : %d\n", philo[i].eat);
		printf("philo sleep : %d\n", philo[i].sleep);
		printf("philo die : %d\n", philo[i].starve);
		printf("philo num_eat : %d\n", philo[i].num_eat);
		printf("---------------------------------\n");
	}
}

int	hold_both_fork(t_philo *philo)
{
	int	success;

	success = 0;
	if (check_fork_stat(philo->l_fork, philo->r_fork))
	{
		hold_fork_right(philo);
		hold_fork_left(philo);
		pthread_mutex_lock(&philo->share->print_mutex);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
		pthread_mutex_unlock(&philo->share->print_mutex);
		success = 1;
	}
	// dprintf(2, "philo %d success %d\n", philo->id, success);
	return (success);
}

int	philo_die(t_philo *philo, int *dead_flag)
{
	pthread_mutex_lock(&(philo->share->dead.mutex));
	*dead_flag = 1;//TODO 이렇게 해도 바뀌나??
	pthread_mutex_unlock(&(philo->share->dead.mutex));
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%zu %d died\n", ft_gettime() - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (-1);
}

int	philo_eat(t_philo *philo, int *not_eat)
{
	size_t		start;
	int			can_eat;

	can_eat = 0;
	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	if (check_fork_stat(philo->l_fork, philo->r_fork))
		can_eat = hold_both_fork(philo);
	if (can_eat == 1)
	{
		pthread_mutex_lock(&(philo->share->print_mutex));
		start = ft_gettime();//TODO ㅇㅣ ㅂㅜ부ㄴ 어케해..
		printf("%zu %d is eating\n", start - philo->birth, philo->id);
		pthread_mutex_unlock(&(philo->share->print_mutex));
		ft_usleep(philo->eat, philo, not_eat);
		philo->num_eat++;
		philo->last_eat = start;
	}
	*not_eat = philo->eat;
	return (0);
}

//죽으면 출력이 더이상 되면 안됨
//mutex_lock(write);
//if (is_die())
//printf();
//mutex_unlock(write);

int	philo_sleep(t_philo *philo, int *not_eat)
{
	size_t	start;

	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	if ((*not_eat + philo->sleep) >= philo->starve)
		return (philo_die(philo, &(philo->share->dead.is_dead)));
	pthread_mutex_lock(&(philo->share->print_mutex));
	start = ft_gettime();//TODO 이부분 어떡하지
	printf("%zu %d is sleeping\n", start - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	// printf("sleep : usleep %d \n", philo->sleep);
	ft_usleep(philo->sleep, philo, not_eat);
	// *not_eat = ft_gettime() - start + *not_eat;
	return (0);
}

int	philo_think(t_philo *philo, int *not_eat)
{
	size_t		start;

	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	pthread_mutex_lock(&(philo->share->print_mutex));
	start = ft_gettime();
	printf("%zu %d is thinking\n", start - philo->birth, philo->id);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	// if (ft_usleep_thinking(philo, not_eat))
	// 	return (1);
	//여긴 좀 다르게!
	// 먹을 수 있을 때 먹되, 가장 오래 굶은 애가 먹어야함.
	*not_eat = ft_gettime() - start + *not_eat;
	return (0);
}

void	*philo_behave(void *philo)
{
	t_philo	*me;
	int		not_eat;
	int		can_eat;
	int		already_printed;

	me = (t_philo *)philo;
	not_eat = 0;
	me->birth = ft_gettime();
	already_printed = 0;
	while (1)
	{
		if (me->share->num_flag == 1 && me->num_eat == me->share->num_of_eat)
			return (0);
		if (is_philo_terminated(philo, &not_eat) == 1)
			return (0);
		philo_eat(philo, &not_eat);
		put_fork_down_left(philo);
		put_fork_down_right(philo);
		philo_sleep(philo, &not_eat);
		philo_think(philo, &not_eat);
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

void	*monitor_behave(void *arg)
{
	t_philo *philo;
	int		num_philo;
	int		i;

	philo = (t_philo *)arg;
	num_philo = philo[0].share->num_of_philo;
	//모니터링 스레드 생성
		// 하는 역할 = 죽은 철학자가 있는지 체크         
		// 횟횟수만큰 먹었는지 체크
		// ㅇㅔ러 발발생생했했으면 끝내기
	i = 0;
	while (i < num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}

int	start_monitoring(pthread_t *monitor, t_share *share, t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_create(monitor, NULL, monitor_behave, (void *)philo) != 0)
		return (handle_error("pthread_create error", share));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_share		share;
	t_philo		*philo;
	pthread_t	monitor;
	int			result;

	memset(&share, 0, sizeof(t_share));
	philo = NULL;
	if (check_argument_validity_and_init_input(argc, argv, &share) == -1)
		return (argument_error_return());
	if (init_all(&share, &philo) == -1)
		return (0);
	start_monitoring(&monitor, &share, philo);
	if (start_all_thread(philo, &share) == -1)
		return (-1);// TODO 다정리!!!!!!!!!!!!!!!!!!!!!!! free 함수 만들기\addinde
	pthread_join(monitor, (void **)&result);
	// wait_thread_end(philo, &share);
	// print_philo(philo, share.num_of_philo);//지워라

	//철학자 생성. 및 실행 함수 만들기 pthread_creat
		//-> 실행함수로 들어가서 동작 시작...]
	//스레드 끝날때까지 기다림 -> 하나가 죽었거나, 정해진 횟수만큼 먹었거나, 어떤 에러가 발생했거나
	// 어쨌든 다 할당 해지 하고 스레드, 뮤텍스 죽여야함.
}

// 가장 마지막에 먹은 시간..
// 에러 처리 함수 정리하기.. 하나로...
// 포크 들때 프린트 해줘야하고
// 먹는 횟수 들어오면 그만큼 하면 멈춰줘야함.