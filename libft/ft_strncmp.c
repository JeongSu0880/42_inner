/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:33:59 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 18:14:36 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			num;

	num = n;
	str1 = s1;
	str2 = s2;
	while ((*str1 == *str2) && num)
	{
		str1++;
		str2++;
		num--;
	}
	if (num == 0)
		return (*(str1 - 1) - *(str2 - 1));
	else
		return (*str1 - *str2);
}
