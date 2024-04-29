/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:17:20 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/02 20:05:24 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			cnt;

	str = (unsigned char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		cnt++;
		str++;
	}
	return (NULL);
}
/*
#include	<string.h>
#include	<stdio.h>

int main(void)
{
	char str[] = "a0a";
	char c = 'e';

	printf("ft : %p\n", ft_memchr(str, 97, 0));
	printf("original : %p\n", memchr(str, 97, 0));
}
*/
