/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:48:11 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 22:20:56 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_isnotspace(char c)
{
	if ((c == ' ') || (c == '\t')
		|| (c == '\n') || (c == '\r')
		|| (c == '\v') || (c == '\f'))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 0;
	num = 0;
	if ((!ft_isdigit(*str) && (*str != '+') 
		&& (*str != '-')) || ft_isnotspace(*str))
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (!ft_isnotspace(*str))
		str++;
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (sign == 1)
		return (-num);
	else
		return (num);
}
