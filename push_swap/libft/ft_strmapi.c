/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:34:17 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/30 21:39:30 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*result;

	idx = 0;
	if (s == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (0);
	while (*(s + idx))
	{
		*(result + idx) = f(idx, *(s + idx));
		idx++;
	}
	*(result + idx) = '\0';
	return (result);
}
/*
#include	<stdio.h>

char lower(unsigned int idx, char c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}

int main(void)
{
	char str[] = "ABC";
	char *result = ft_strmapi(str, &lower);

	printf("%s\n", result);
}
*/
