/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/11 22:12:54 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void *p_function(void * data)
// {
//   pid_t pid; //process id
//   pthread_t tid; // thread id

//   pid = getpid(); //4
//   tid = pthread_self();

//   char* thread_name = (char *)data;
//     printf("thread name : %s, tid : %x, pid : %u\n", thread_name, (unsigned int)tid, (unsigned int)pid); //5
//   return (0);
// }

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi_check_int(char *str)
{
	long long	num;

	num = 0;
	while (str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (-1);
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num < 0 || num > 2147483647)
		return (-1);
	return ((int)num);
}

void	init_input(int num, int i, t_state *state)
{
	if (i == 1)
		state->num_of_philo = num;
	else if (i == 2)
		state->time_to_die = num;
	else if (i == 3)
		state->time_to_eat = num;
	else if (i == 4)
		state->time_to_sleep = num;
	else if (i == 5)
	{
		state->num_flag = 1;
		state->num_of_eat = num;
	}
}

int	check_argument_validity_and_init_input\
	(int argc, char *argv[], t_state *state)
{
	int	i;
	int	num;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (-1);
	state->num_flag = -1;
	while (i < argc)
	{
		num = ft_atoi_check_int(argv[i]);
		if (num == -1)
			return (-1);
		init_input(num, i, state);
		i++;
	}
	return (0);
}

int	argument_error_return()
{
	printf("Wrong argument!");
	return (1);
}

void	init_state(t_state *state)
{
	int	i;

	i = 0;
	state->fork = (t_fork *)malloc(sizeof(t_fork) * state->num_of_philo);
	state->philo = (t_philo *)malloc(sizeof(t_philo) * state->num_of_philo);
	while (i < state->num_of_philo)
	{
		pthread_mutex_init(&state->fork[i].mutex, NULL);
		state->fork[i].fork_stat = 0;
		state->philo->id = i;
		state->philo->eat = state->time_to_eat;
		state->philo->sleep = state->time_to_sleep;
		state->philo->die = state->time_to_die;
		state->philo->num_eat = 0;
		i++;
	}
	pthread_mutex_init(&state->dead.mutex, NULL);
	state->dead.is_dead = 0;
}

int	main(int argc, char *argv[])
{
	t_state	state;

	if (check_argument_validity_and_init_input(argc, argv, &state) == -1)
		return (argument_error_return());
	init_state(&state);
	
  // pthread_t pthread[2];
  // int thr_id;
  // int status;
  // char p1[] = "thread_1";
  // char p2[] = "thread_2";
  // char p3[] = "thread_3";

  // sleep(1); //1

  // thr_id = pthread_create(&pthread[0], NULL, p_function, (void*)p1); //2
  // if(thr_id < 0)
  // {
  //   perror("pthread0 create error");
  //   exit(EXIT_FAILURE);
  // }

  // thr_id = pthread_create(&pthread[1], NULL, p_function, (void *)p2); //2
  // if(thr_id < 0)
  // {
  //   perror("pthread1 create error");
  //   exit(EXIT_FAILURE);
  // }

  // p_function((void *)p3); //3

  // pthread_join(pthread[0], (void **)&status); //6
  // pthread_join(pthread[1], (void **)&status);

  // printf("end??\n");
  // return 0;
}