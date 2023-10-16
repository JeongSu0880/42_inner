/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:03 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/16 21:25:30 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	find_str(const char *haystack_portion, const char *needle)
{
	char	*s_portion;
	char	*n;

	s_portion = (char *)haystack_portion;
	n = (char *)needle;
	while (*n != 0)
	{
		if (*s_portion != *n)
		{
			return (0);
		}
		n++;
		s_portion++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*find;
	size_t	i;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (*find == '\0')
		return (str);
	while (i < len)
	{
		if (*find == *str)
		{
			if (find_str(str, find))
				return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}
