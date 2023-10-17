/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:11:58 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/17 20:45:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*tmp_ptr;
	size_t			iter;

	iter = 0;
	tmp_ptr = ptr;
	while (iter < num)
	{
		*(tmp_ptr + iter) = 0;
		iter++;
	}
}
/*
#include	<strings.h>
#include	<stdio.h>

int main(void)
{
	char sample1[] = "123456";
	char sample2[] = "123456";

	bzero(sample1, 3);
	ft_bzero(sample2, 3);
	printf("bzero : %s\n", sample1);
	printf("ft_bzero : %s\n", sample2);
	return (0);
}
*/
