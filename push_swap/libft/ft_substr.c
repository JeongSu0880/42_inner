/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:06:58 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/04 14:38:12 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	put_value(char *malloc_arr, char *original_arr, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx + 1 < len)
	{
		*(malloc_arr + idx) = *(original_arr + idx);
		idx++;
	}
	*(malloc_arr + idx) = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
	{
		result = (char *)malloc(1);
		if (result == NULL)
			return (0);
		*result = '\0';
		return (result);
	}
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start) + 1;
	else
		len = len + 1;
	result = (char *)malloc(sizeof(char) * len);
	if (result == NULL)
		return (0);
	put_value(result, (char *)(s + start), len);
	return (result);
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
