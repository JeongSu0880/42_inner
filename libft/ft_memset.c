/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:51:29 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/13 21:27:01 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = ptr;
	while (num--)
	{
		*tmp_ptr = value;
		tmp_ptr++;
	}
	return (ptr);
}
