/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:48:11 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/31 15:03:11 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t')
		|| (c == '\n') || (c == '\r')
		|| (c == '\v') || (c == '\f'))
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

int	ft_atoi(const char *str)
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
	return ((int)num * sign);
}
/*
#include	<stdio.h>
#include	<stdlib.h>

int main(int argc, char **argv)
{
	printf("atoi : %d\n", atoi(argv[1]));
	printf("ft_atoi : %d\n", ft_atoi(argv[1]));
	return (0);
}
*/
//os에 따라
//반환값이 어차피 int