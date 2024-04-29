/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:40 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/07 21:21:54 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*pass_c(char *s, char c)
{
	size_t	idx;
	char	*addr;

	idx = 0;
	while (*(s + idx) == c)
		idx++;
	addr = s + idx;
	return (addr);
}

static size_t	word_cnt(char *s, char c)
{
	size_t	iter;
	size_t	cnt;
	char	*s_tmp;

	cnt = 0;
	iter = 0;
	s_tmp = pass_c(s, c);
	if (*s_tmp == '\0')
		return (0);
	while (*(s_tmp + iter + 1) != '\0')
	{
		if (*(s_tmp + iter) == c && *(s_tmp + iter + 1) != c)
			cnt++;
		iter++;
	}
	return (cnt + 1);
}

static void	ft_free(char **arr, size_t	idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**word_alloc(char **arr, char *s, char c, size_t size)
{
	size_t	arr_idx;
	size_t	s_idx;
	size_t	letter_cnt;
	char	*next;

	arr_idx = 0;
	next = s;
	s_idx = 0;
	while (arr_idx < size)
	{
		next = pass_c(next + s_idx, c);
		s_idx = 0;
		letter_cnt = 0;
		while (*(next + s_idx) != '\0' && *(next + s_idx++) != c)
			letter_cnt++;
		*(arr + arr_idx) = (char *)malloc(sizeof(char) * (letter_cnt + 1));
		if (*(arr + arr_idx) == NULL)
		{
			ft_free(arr, arr_idx);
			return (0);
		}
		ft_strlcpy(*(arr + arr_idx), next, letter_cnt + 1);
		arr_idx++;
	}
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	size_t	words_size;

	if (s == 0)
		return (0);
	if (*s == '\0')
	{
		result = (char **)malloc(sizeof(char *));
		if (result == NULL)
			return (0);
		*result = 0;
		return (result);
	}
	words_size = word_cnt((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (words_size + 1));
	if (result == NULL)
		return (0);
	if (word_alloc(result, (char *)s, c, words_size) == 0)
		return (0);
	*(result + words_size) = NULL;
	return (result);
}
// #include	<stdio.h>

// int main(void)
// {
// 	char	str[] = "hello!";
// 	char	c = '\0';
// 	char	**arr = ft_split("\0aa\0bbb", '\0');
// 	int	i = 0;

// 	while (arr[i][0] != '\0')
// 	{
// 		printf("%s\n", *(arr + i));
// 		i++;
// 	}

// 	i = 0;
// 	while (arr[i][0] != '\0')
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr[i]);
// 	free(arr);
// }