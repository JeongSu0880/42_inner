/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:08:44 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/15 17:58:35 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	argument_error_return(void)
{
	printf("Wrong argument!");
	return (1);
}

int	handle_error(char *str, t_share *share)
{
	int	i;

	i = 0;
	printf("error : %s\n", str);
	pthread_mutex_lock(&(share->error.mutex));
	share->error.is_error = 1;
	pthread_mutex_unlock(&(share->error.mutex));
	return (-1);
}