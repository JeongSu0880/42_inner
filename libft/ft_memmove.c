/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:31 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 11:53:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			len;

	if (src == dest)
		return (dest);
	if (src < dest)
	{
		len = num;
		while (len > 0)
		{
			--len;
			*(unsigned char *)(dest + len) = *(unsigned char *)(src + len);
		}
	}
	else
	{
		len = 0;
		while (len < num)
		{
			*(unsigned char *)(dest + len) = *(unsigned char *)(src + len);
			len++;
		}
	}
	return (dest);
}
