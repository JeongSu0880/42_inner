/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:38:02 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/26 19:54:42 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char	*ft_strchr_2(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

static int	check_index(char *s, char *set, size_t *s_idx, size_t *e_idx)
{
	size_t	idx;

	idx = 0;
	while (ft_strchr_2(set, *(s + idx)))
		idx++;
	*s_idx = idx;
	if (idx >= ft_strlen(s))
		return (0);
	idx = ft_strlen(s) - 1;
	while (idx > 0 && ft_strchr_2(set, *(s + idx)))
		idx--;
	*e_idx = idx;
	return (1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*arr;
	size_t	start_idx;
	size_t	end_idx;
	int		idx;
	int		flag;

	start_idx = 0;
	end_idx = ft_strlen(s1) - 1;
	if (set != 0)
		flag = check_index((char *)s1, (char *)set, &start_idx, &end_idx);
	arr = (char *)malloc(sizeof(char) * (end_idx - start_idx + 2));
	if (arr == NULL)
		return (0);
	idx = -1;
	if (flag == 0)
	{
		*arr = '\0';
		return (arr);
	}
	while (start_idx + ++idx <= end_idx)
		*(arr + idx) = *(s1 + start_idx + idx);
	*(arr + idx) = '\0';
	return (arr);
}
/*
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "";
	char	str2[] = "";
	char	*arr;

	arr = ft_strtrim(str1, str2);
	printf("len : %zu", ft_strlen(arr));
	printf("%s\n", arr);
	free(arr);
}
*/
