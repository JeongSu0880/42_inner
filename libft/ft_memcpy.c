/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:52 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/13 21:25:29 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*dest_tmp;
	unsigned char	*source_tmp;

	if (dest == source)
		return (dest);
	dest_tmp = dest;
	source_tmp = source;
	while (num--)
	{
		*dest_tmp = *source_tmp;
		dest_tmp++;
		source_tmp++;
	}
	return (dest);
}
