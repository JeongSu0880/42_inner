/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:48 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 17:14:49 by jungslee         ###   ########.fr       */
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

typedef struct	s_error
{
	pthread_mutex_t mutex;
	int				is_error;
}	t_error;

typedef struct s_share
{
	t_fork			*fork;//TODO 이거 어케할지
	t_dead			*dead;
	t_error			*error;
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
	size_t			life;
	int				num_flag;
	int				num_must_eat;
	int				num_ate;
	size_t			last_eat;
	int				pre_behave;
	struct s_fork	*r_fork;
	struct s_fork	*l_fork;
}	t_philo;

/*argument_check_and_init.c*/
int	init_all(t_share *share, t_philo **philo);
int	check_argument_validity_and_init_input(int argc, char *argv[], \
											t_share *share);

/*error.c*/
int		argument_error_return(void);
int		handle_error(char *str, t_share *share);
void	set_error(t_error *error);

/*action.c*/
void	reach_hand_right(t_philo *philo);
void	reach_hand_left(t_philo *philo);
void	fold_arm_right(t_philo *philo);
void	fold_arm_left(t_philo *philo);
int	hold_fork_right(t_philo *philo);
int	hold_fork_left(t_philo *philo);
void	put_fork_down_right(t_philo *philo);
void	put_fork_down_left(t_philo *philo);

/*utils.c*/
size_t		ft_gettime(void);
char	*ph_itoa(int n);
int		is_philo_terminated(t_philo *philo);
int	ft_usleep(size_t ms, t_philo *philo);
int	check_is_dead(t_dead *dead);

/*action_2.c*/
int	check_reach_done(t_fork *l_fork, t_fork *r_fork);
int	check_is_occupied(t_fork *l_fork, t_fork *r_fork);
int	check_fork_stat(t_fork *l_fork, t_fork *r_fork);
int	philo_die(t_philo *philo, int *dead_flag, int print_flag);
int	hold_both_fork(t_philo *philo);

/*clean.c*/
void	destroy_all_mutex(t_share *share);
void	free_all(t_philo *philo, t_share *share);

#endif