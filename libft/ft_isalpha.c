/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:36:50 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 19:57:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
#include	<ctype.h>
#include	<stdio.h>

int main(void)
{
	printf("%d\n", ft_isalpha('d'));
	printf("%d\n", isalpha('d'));
}
*/
