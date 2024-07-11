/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:48 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/11 22:11:32 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int	id;
	int	eat;
	int	sleep;
	int	think;
	int	die;
	int	num_eat;
} t_philo;

typedef struct s_fork
{
	pthread_mutex_t mutex;
	int 			fork_stat;
} t_fork;

typedef struct s_dead
{
	pthread_mutex_t	mutex;
	int				is_dead;
} t_dead;

typedef struct s_state
{
	struct s_fork	*fork;
	struct s_philo	*philo;
	struct s_dead	dead;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_flag;
	int				num_of_eat;
	
} t_state;

#endif