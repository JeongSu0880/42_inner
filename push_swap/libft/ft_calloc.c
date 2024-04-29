/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:20:14 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/28 17:09:51 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(size * count);
	if (arr == NULL)
		return (0);
	ft_bzero(arr, size * count);
	return (arr);
}
/*
#include	<stdio.h>
#include	<stdlib.h>

int	main(void)
{
	char *str1;
	char *str2;

	str1 = ft_calloc(5, 4);
	str2 = calloc(5, 4);
	write(1, str1, 20);
	write(1, str2, 20);
	free(str1);
	free(str2);
}
*/
