/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:08:44 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/25 19:37:38 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	argument_error_return(void)
{
	printf("Wrong argument!");
	return (1);
}

int	handle_error(char *str)
{
	int	i;

	i = 0;
	printf("error : %s\n", str);
	return (ERROR_RETURN);
}
