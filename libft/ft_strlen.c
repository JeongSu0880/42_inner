/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:13 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:49:05 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	printf("ft : %lu\n", ft_strlen("jungslee"));
	printf("original : %lu\n", strlen("jungslee"));
}
*/
