/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:18:26 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/23 14:52:03 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*arr;
	size_t	idx1;
	size_t	idx2;
	size_t	len;

	idx1 = 0;
	idx2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	while (idx1 < len)
	{
		if (idx1 < ft_strlen(s1))
			*(arr + idx1) = *(s1 + idx1);
		else
		{
			*(arr + idx1) = *(s2 + idx2);
			idx2++;
		}
		idx1++;
	}
	*(arr + idx1) = '\0';
	return (arr);
}
/*
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "aaaaa";
	char	str2[] = "bbb";
	char	*result = ft_strjoin(str1, str2);

	printf("%s\n", result);
	free(result);
}
*/
