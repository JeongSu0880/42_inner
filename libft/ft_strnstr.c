/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:24:03 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 17:12:38 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	iter;
	size_t	needle_len;

	needle_len = ft_strlen((char *)needle);
	iter = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack && (iter + needle_len <= len))
	{
		if (ft_strncmp(haystack + iter, needle, needle_len) == 0)
		{
			return ((char *)(haystack + iter));
		}
		iter++;
	}
	return (0);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	haystack[] = "";
	char	needle[] = "fake";

	printf("%c", *ft_strnstr(((void *)0), "fake", 3));
	//ft_strnstr(haystack, needle, 3);
	//strnstr(NL, needle, 3);
}
*/
