/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:32:52 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_behave(void *philo)
{
	t_philo	*me;
	t_share	*share;
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
	int		i;
	size_t	time;

	i = 0;
	time = ft_gettime();
	while (i < share->num_of_philo)
	{
		philo[i].birth = time;
		if (pthread_create(&(philo[i].thread), NULL, philo_behave, \
			(void *)&(philo[i])) < 0)
			return (handle_error("pthread_create error", share));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_share		*share;
	t_philo		*philo;

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
	wait_thread_end(philo, share);
	free_all(philo, share);
	destroy_all_mutex(share);
	return (0);
}
