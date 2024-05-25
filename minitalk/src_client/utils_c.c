/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:08:12 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/12 19:31:50 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	pow_2(int num)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (i < num)
	{
		ret = ret * 2;
		i++;
	}
	return (ret);
}

void	handle_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
