/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:06:38 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/17 17:37:52 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	is_philo_terminated(t_philo *philo)
// {
	
// }

int	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_philo_terminated(t_philo *philo, int *not_eat)
{
	if (*not_eat >= philo->starve)
	{
		philo_die(philo, &(philo->share->dead.is_dead));
		return (1);
	}
	if (philo->share->dead.is_dead == 1)
		return (1);
	return (0);
}

int	ft_usleep(int ms, t_philo *philo, int *not_eat)
{
	int	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (is_philo_terminated(philo, not_eat))
			break ;
		usleep(250);
		*not_eat += ft_gettime() - start;
	}
	return (0);
}

int	ft_usleep_thinking(t_philo *philo, int *not_eat)
{
	int	start;
	int	can_eat;

	start = ft_gettime();
	can_eat = 0;
	while (1)
	{
		if (is_philo_terminated(philo, not_eat))
			break ;
		if (philo->l_fork->fork_stat == 0 && philo->r_fork->fork_stat == 0)
		{
			can_eat = hold_both_fork(philo);
			if (can_eat == 1)// 여기에 가장 오래 굶은 철학자가 먼저 먹게 하는 조건 추가.
				break ;
		}
		usleep(250);
		*not_eat += ft_gettime() - start;
	}
	return (0);
}

// static void	cnt_num(long long tmp_num, size_t *cnt)
// {
// 	while (tmp_num)
// 	{
// 		(*cnt)++;
// 		tmp_num = tmp_num / 10;
// 	}
// }

// static void	transfer(char *result, int cnt, long long tmp)
// {
// 	int	idx;

// 	idx = cnt - 1;
// 	while (idx >= 0)
// 	{
// 		*(result + idx) = tmp % 10 + '0';
// 		tmp = tmp / 10;
// 		idx--;
// 	}
// 	*(result + cnt) = '\0';
// }

// char	*ph_itoa(int n)
// {
// 	char		*result;
// 	int			cnt;
// 	long long	tmp;

// 	cnt = 0;
// 	tmp = (long long)n;
// 	cnt_num(tmp, &cnt);
// 	if (!tmp)
// 	{
// 		result = (char *)malloc(sizeof(char) * 2);
// 		if (result == NULL)
// 			return (0);
// 		*result = '0';
// 		*(result + 1) = '\0';
// 	}
// 	else
// 	{
// 		result = (char *)malloc(sizeof(char) * (cnt + 1));
// 		if (result == NULL)
// 			return (0);
// 		transfer(result, cnt, tmp);
// 	}
// 	return (result);
// }
