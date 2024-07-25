/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:08:23 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:04:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void    print_str(t_philo *philo, che)
// {
    
// }

int   print_hold_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->share->print_mutex);
    if (check_is_dead(philo->share->dead))
    {
        pthread_mutex_unlock(&(philo->share->print_mutex));
        return (DEAD_RETURN);
    }
    printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
    printf("%zu %d has taken a fork\n", ft_gettime() - philo->birth, philo->id);
    pthread_mutex_unlock(&philo->share->print_mutex);
    return (TRUE);
}