/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:33:59 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 14:59:17 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			num;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	num = 0;
	while (num < n && (*(str1 + num) || *(str2 + num)))
	{
		if (*(str1 + num) != *(str2 + num))
			return (*(str1 + num) - *(str2 + num));
		num++;
	}
	return (0);
}
/*
#include	<stdio.h>
#include	<string.h>

int	main(void)
{
	char s1[] = "atoms\0\0\0\0";
	char s2[] = "atomsee\0abc";
	int	result1 = strncmp(s1, s2, 8);
	int result2 = ft_strncmp(s1, s2, 8);

	printf("strncmp : %d\nft_strncmp : %d\n", result1, result2);
}
*/
