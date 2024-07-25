/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:48 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:31:12 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define ERROR_RETURN -1
# define DEAD_RETURN -2
# define DONE_EAT 2

# define TRUE 1
# define FALSE 0

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				is_occupied;
	int				reach;
}	t_fork;

typedef struct s_dead
{
	pthread_mutex_t	mutex;
	int				is_dead;
}	t_dead;

typedef struct s_share
{
	t_fork			*fork;
	t_dead			*dead;
	pthread_mutex_t	print_mutex;
	int				num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_flag;
	int				num_of_eat;
}	t_share;

typedef struct s_philo
{
	t_share			*share;
	pthread_t		thread;
	int				id;
	size_t			birth;
	size_t			eat;
	size_t			sleep;
	size_t			starve;
	int				num_flag;
	int				num_must_eat;
	int				num_ate;
	size_t			last_eat;
	struct s_fork	*r_fork;
	struct s_fork	*l_fork;
}	t_philo;

/*action.c*/
int		hold_fork_right(t_philo *philo);
int		hold_fork_left(t_philo *philo);
void	put_fork_down_right(t_philo *philo);
void	put_fork_down_left(t_philo *philo);

/*argument_check_and_init.c*/
int		check_argument_validity_and_init_input(int argc, char *argv[], \
											t_share *share);

/*argument_check_and_init_2.c*/
int		init_all(t_share *share, t_philo **philo);

/*clean_malloc.c*/
void	destroy_all_mutex(t_share *share);
void	free_all(t_philo *philo, t_share *share);
void	wait_thread_end(t_philo *philo, t_share *share);

/*error.c*/
int		argument_error_return(void);
int		handle_error(char *str, t_share *share);

/*philo_behave.c*/
int		hold_both_fork(t_philo *philo);
int		philo_die(t_philo *philo, int *dead_flag, int print_flag);
int		philo_sleep(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_think(t_philo *philo);

/*print.c*/
int		print_hold_fork(t_philo *philo);
int		print_eat(t_philo *philo);

/*utils.c*/
size_t	ft_gettime(void);
int		is_philo_terminated(t_philo *philo);
int		ft_usleep(size_t ms, t_philo *philo);
int		check_is_dead(t_dead *dead);

#endif