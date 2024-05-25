/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:38:48 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/17 20:36:33 by jungslee         ###   ########.fr       */
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
