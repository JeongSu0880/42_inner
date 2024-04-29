/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:13 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/04 14:25:26 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str != NULL && str[cnt])
		cnt++;
	return (cnt);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	*str = NULL;
	printf("ft : %lu\n", ft_strlen(str));
	printf("original : %lu\n", strlen(str));
}
*/
