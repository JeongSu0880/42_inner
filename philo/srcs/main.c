/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/17 17:45:41 by jungslee         ###   ########.fr       */
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
	reach_hand_right(philo);
	if (philo->l_fork->fork_stat == 0 && philo->l_fork->reach == 0)
		reach_hand_left(philo);
	else
		fold_arm_right(philo);
	if (philo->r_fork->reach == 1 && philo->l_fork->reach == 1)
	{
		hold_fork_right(philo);
		hold_fork_left(philo);
		success = 1;
	}
	return (success);
}

int	philo_die(t_philo *philo, int *dead_flag)
{
	int	start;

	start = ft_gettime();
	pthread_mutex_lock(&(philo->share->dead.mutex));
	*dead_flag = 1;//TODO 이렇게 해도 바뀌나??
	pthread_mutex_unlock(&(philo->share->dead.mutex));
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%dms [%d]philo died\n", start, philo->id + 1);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	return (-1);
}

int	philo_eat(t_philo *philo, int *not_eat)
{
	int		start;

	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	start = ft_gettime();
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%dms [%d]philo is eating\n", start, philo->id + 1);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	ft_usleep(philo->eat, philo, not_eat);
	*not_eat = philo->eat;
	philo->last_eat = start;
	return (0);
}

int	philo_sleep(t_philo *philo, int *not_eat)
{
	int		start;

	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	if ((*not_eat + philo->sleep) >= philo->starve)
		return (philo_die(philo, &(philo->share->dead.is_dead)));
	start = ft_gettime();
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%dms [%d]philo is sleeping\n", start, philo->id + 1);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	ft_usleep(philo->sleep, philo, not_eat);
	*not_eat = ft_gettime() - start + *not_eat;
	return (0);
}

int	philo_think(t_philo *philo, int *not_eat)
{
	int		start;

	if (is_philo_terminated(philo, not_eat) == 1)
		return (-1);
	start = ft_gettime();
	pthread_mutex_lock(&(philo->share->print_mutex));
	printf("%dms [%d]philo is thinking\n", start, philo->id + 1);
	pthread_mutex_unlock(&(philo->share->print_mutex));
	ft_usleep_thinking(philo, not_eat);
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

	me = (t_philo *)philo;
	not_eat = 0;
	//홀수 왼쪽 짝수 오른쪽부터 먹기
	// 바로 전에 먹은 다음은 바로 자야 해!
	// 자고 난 다음은 바로 띵크 해야해!
	if (me->id % 2 == 1)
	{
		while (1)
		{
			if (is_philo_terminated(philo, &not_eat) == 1)
				return (0);
			if (me->l_fork->fork_stat == 0 && me->r_fork->fork_stat == 0)
				can_eat = hold_both_fork(me);
			if (can_eat == 1)
			{
				philo_eat(philo, &not_eat);
				philo_sleep(philo, &not_eat);
			}
			else
				philo_think(philo, &not_eat);
			//think 하기
		}
	}
	else if (me->id % 2 == 0)
	{
		philo_think(philo, &not_eat);
		while (1)
		{
			if (is_philo_terminated(philo, &not_eat) == 1)
				return (0);
			if (me->l_fork->fork_stat == 0 && me->r_fork->fork_stat == 0)
				can_eat = hold_both_fork(me);
			if (can_eat == 1)
			{
				philo_eat(philo, &not_eat);
				philo_sleep(philo, &not_eat);
			}
			else
				philo_think(philo, &not_eat);
		}
	}
	//죽는 조건
	// starve 타임 찼을 때
	// 

	//에러 처리
	return (0);
}

int	start_all_thread(t_philo *philo, t_share *share)
{
	int	i;

	while (i < share->num_of_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, philo_behave, (void *)&(philo[i])) < 0)
			return (handle_error("pthread_create error", share));
		i++;
		usleep(5);// TODO 이거 하는게 맞나.
	}
	return (0);
}

void	*monitor_behave(void *arg)
{
	t_philo *philo;
	int		num_philo;
	int		i;
	// intresult;

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

// void	wait_thread_end(t_philo *philo, t_share *share)
// {
	
// }

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
		return (-1);// TODO 다정리!!!!!!!!!!!!!!!!!!!!!!! free 함수 만들기
	pthread_join(monitor, (void **)&result);
	// wait_thread_end(philo, &share);
	// print_philo(philo, share.num_of_philo);//지워라

	//철학자 생성. 및 실행 함수 만들기 pthread_creat
		//-> 실행함수로 들어가서 동작 시작...]
	//스레드 끝날때까지 기다림 -> 하나가 죽었거나, 정해진 횟수만큼 먹었거나, 어떤 에러가 발생했거나
	// 어쨌든 다 할당 해지 하고 스레드, 뮤텍스 죽여야함.
}

// 프린트 하기 
// get_time_of_day 하기
// 가장 마지막에 먹은 시간..
// 에러 처리 함수 정리하기.. 하나로...
// 포크 들때 프린트 해줘야하고
// 먹는 횟수 들어오면 그만큼 하면 멈춰줘야함.