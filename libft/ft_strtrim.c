/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:38:02 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/06 21:45:47 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	check_index(char *s, char *set, size_t *s_idx, size_t *e_idx)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx) && ft_strchr(set, *(s + idx)))
		idx++;
	*s_idx = idx;
	if (idx >= ft_strlen(s))
	{
		*e_idx = idx;
		return (1);
	}
	idx = ft_strlen(s) - 1;
	while (idx > 0 && ft_strchr(set, *(s + idx)))
		idx--;
	*e_idx = idx;
	return (*e_idx - *s_idx + 2);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*arr;
	size_t	start_idx;
	size_t	end_idx;
	int		idx;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start_idx = 0;
	end_idx = 0;
	len = check_index((char *)s1, (char *)set, &start_idx, &end_idx);
	arr = (char *)malloc(sizeof(char) * len);
	if (arr == NULL)
		return (0);
	idx = 0;
	while (len != 1 && start_idx + idx <= end_idx)
	{
		*(arr + idx) = *(s1 + start_idx + idx);
		idx++;
	}
	*(arr + idx) = '\0';
	return (arr);
}
// #include	<stdio.h>
// int	main(void)
// {
// 	char	str1[] = "";
// 	char	str2[] = "";
// 	char	*arr;
// 	arr = ft_strtrim(str1, str2);
// 	printf("len : %zu\n", ft_strlen(arr));
// 	printf("%s\n", arr);
// 	free(arr);
// }
