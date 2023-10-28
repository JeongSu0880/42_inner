/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:06:58 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:19 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	alloc_value(char *arr1, char *arr2, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx + 1 < len)
	{
		*(arr1 + idx) = *(arr2 + idx);
		idx++;
	}
	*(arr1 + idx) = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*arr;

	if (start >= ft_strlen(s))
	{
		arr = (char *)malloc(1);
		if (arr == NULL)
			return (0);
		*arr = '\0';
		return (arr);
	}
	else if (ft_strlen(s + start) <= len)
	{
		arr = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
		if (arr == NULL)
			return (0);
		alloc_value(arr, (char *)(s + start), ft_strlen(s + start) + 1);
	}
	else
	{
		arr = (char *)malloc(sizeof(char) * (len + 1));
		if (arr == NULL)
			return (0);
		alloc_value(arr, (char *)(s + start), len + 1);
	}
	return (arr);
}
/*
#include	<stdio.h>

int	main(void)
{
	char	main_str[] = "lorem ipsu lekj";
	char	*str;

	str = ft_substr(main_str, 0, 10);
	printf("%s\n", str);

	free(str);
}
*/
