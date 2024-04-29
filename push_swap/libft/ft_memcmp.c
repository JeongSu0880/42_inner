/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:31:34 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/06 19:49:29 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				cmp;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cmp = *str1 - *str2;
	while (i < n && (cmp == 0))
	{
		cmp = *(str1 + i) - *(str2 + i);
		i++;
	}
	return (cmp);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcddd";

	printf("ft : %d\n", ft_memcmp(str1, str2, 5));
	printf("original : %d\n", memcmp(str1, str2, 5));

}
*/
