/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:15:50 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/17 17:43:17 by jungslee         ###   ########.fr       */
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
	if (c == '\0')
		add = tmp;
	return (add);
}
