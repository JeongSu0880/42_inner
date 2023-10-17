/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:52 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/17 21:48:46 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*dest_tmp;
	unsigned char	*source_tmp;
	size_t			iter;

	iter = 0;
	dest_tmp = (unsigned char *)dest;
	source_tmp = (unsigned char *)source;
	if (dest == source)
		return (dest);
	while (iter < num)
	{
		*(dest_tmp + iter) = *(source_tmp + iter);
		iter++;
	}
	return (dest);
}
