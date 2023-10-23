/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:51:29 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:35:35 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*tmp_ptr;
	size_t			iter;

	tmp_ptr = ptr;
	iter = 0;
	while (iter < num)
	{
		*(tmp_ptr + iter) = value;
		iter++;
	}
	return (ptr);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "aaaaaAa";
	char	str2[] = "aaaaaAa";

	printf("ft : %s\n", ft_memset(str1, 'b', 5));
	printf("original : %s\n", memset(str2, 'b', 5));
}
*/
