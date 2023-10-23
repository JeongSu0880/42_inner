/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:15:50 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:51:48 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*add;

	tmp = (char *)s;
	add = NULL;
	while (*tmp)
	{
		if (*tmp == (char)c)
			add = tmp;
		tmp++;
	}
	if ((char)c == '\0')
		add = tmp;
	return (add);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	printf("ft : %s\n", ft_strrchr("newjeans e hypeboy yo", 'y'));
	printf("original : %s\n", strrchr("newjeans e hypeboy yo", 'y'));
}
*/
