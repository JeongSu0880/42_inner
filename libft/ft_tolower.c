/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:07:32 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:53:57 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		c += 32;
	return (c);
}
/*
#include	<ctype.h>
#include	<stdio.h>

int main(void)
{
	printf("ft : %c\n", ft_tolower('A'));
	printf("original : %c\n", tolower('A'));
}
*/
