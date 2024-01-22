/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:18:54 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/08 20:26:49 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	while ((dst_len + i + 1 < size) && *(src + i))
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	*(dst + dst_len + i) = '\0';
	if (dst_len < size)
		return (src_len + dst_len);
	else
		return (src_len + size);
}

#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	str1[8] = "";
	char	str2[8] = "abc";
	char	cat[] = "def";

	printf("ft result : %lu, cat : %s\n", ft_strlcat(str1, cat, 6), str1);
	printf("original result : %lu, cat : %s\n", strlcat(str2, cat, 6), str2);
}

