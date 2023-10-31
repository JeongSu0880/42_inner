/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:40 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/30 22:31:06 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	word_cnt(char *trim, char c)
{
	size_t	iter;
	size_t	cnt;

	cnt = 0;
	iter = 0;
	while (*(trim + iter) && *(trim + iter + 1) != '\0')
	{
		if (*(trim + iter) == c && *(trim + iter + 1) != c)
			cnt++;
		iter++;
	}
	return (cnt);
}

char	*pass_c(char *s, char c)
{
	size_t	idx;
	char	*addr;

	idx = 0;
	while (*(s + idx) == c)
		idx++;
	addr = s + idx;
	return (addr);
}

static char	**word_alloc(char **arr, char *s, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	letter_cnt;
	char	*next;

	i = 0;
	j = 0;
	letter_cnt = 0;
	next = s;
	while (i < size)
	{
		while (*(next + j) != '\0' && *(next + j++) != c)
			letter_cnt++;
		*(arr + i) = (char *)malloc(sizeof(char) * (letter_cnt + 1));
		if (*(arr + i) == NULL)
			return (0);
		ft_strlcpy(*(arr + i), next, letter_cnt + 1);
		i++;
		next = pass_c(next + j, c);
		j = 0;
		letter_cnt = 0;
	}
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*s_trim;
	size_t	words_size;

	s_trim = ft_strtrim(s, &c);
	if (*s_trim == '\0')
	{
		result = (char **)malloc(1);
		if (result == NULL)
			return (0);
		*result = NULL;
		free(s_trim);
		return (result);
	}
	words_size = word_cnt(s_trim, c) + 1;
	result = (char **)malloc(sizeof(char *) * (words_size + 1));
	if (result == NULL)
		return (0);
	if (word_alloc(result, s_trim, c, words_size) == NULL)
	{
		free(result);
		return (0);
	}
	*(result + words_size) = NULL;
	free(s_trim);
	return (result);
}

// #include	<stdio.h>

// int main(void)
// {
// 	char	str[] = "hello!";
// 	char	c = ' ';
// 	char	**arr = ft_split(str, ' ');
// 	int	i = 0;

// 	while (*(arr + i))
// 	{
// 		printf("%s\n", *(arr + i));
// 		i++;
// 	}

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }

