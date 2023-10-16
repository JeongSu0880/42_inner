/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:11:58 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/13 16:32:17 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = ptr;
	while (num--)
	{
		*tmp_ptr = 0;
		tmp_ptr++;
	}
}
