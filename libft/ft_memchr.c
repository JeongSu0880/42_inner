/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:17:20 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 19:11:04 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			cnt;

	str = s;
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
