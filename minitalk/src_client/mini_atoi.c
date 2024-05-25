/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:31:18 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/13 19:01:14 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t')
		|| (c == '\n') || (c == '\r')
		|| (c == '\v') || (c == '\f'))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_issign(char c)
{
	if (c == '+' || ft_isdigit(c))
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

long long	ft_atoi(char *str)
{
	long long	num;
	int			sign;

	sign = 0;
	num = 0;
	while (ft_isspace(*str))
		str++;
	sign = ft_issign(*str);
	if (sign && !ft_isdigit(*str))
		str++;
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
		if (num < 0)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
	}
	return (num * sign);
}
