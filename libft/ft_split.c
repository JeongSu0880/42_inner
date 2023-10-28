/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:40 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/28 22:02:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	word_cnt(char *trim, char c)
{
	size_t	iter;
	size_t	cnt;

	cnt = 0;
	iter = 0;
	while (*(trim + iter))
	{
		if (*(trim + iter) == c && *(trim + iter + 1) != c)
			cnt++;
		iter++;
	}
	return (cnt);
}

static size_t	

char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*s_trim;
	size_t	iter;
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
	iter = 0;
	words_size = word_cnt(s_trim, c) + 1;
	result = (char **)malloc(sizeof(char) * (words_size + 1));
	if (result == NULL)
	{
		free(result);
		return (0);
	}
	word_alloc(result, s_trim, c, words_size);
	*(result + words_size) = NULL;
	free(s_trim);
	return (result);
}
/*
#include	<stdio.h>

int main(void)
{
	char	str[] = ",,dog,cat,parrot,,";
	char	c = ',';
	char	**arr = ft_split(str, ',');
	int	i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
*/
