/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:41:02 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 14:14:18 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len + 1 < size)
	{
		ft_memcpy(dest, src, src_len);
		*(dest + src_len) = '\0';
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		*(dest + size) = '\0';
	}
	return (src_len);
}
