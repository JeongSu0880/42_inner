/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:12:32 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:40:57 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return (tmp);
	return (NULL);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "fuction";
	char	c = 'c';

	printf("ft : %s\n", strchr(str1, c));
	printf("original : %s\n", ft_strchr(str1, c));
}
*/
