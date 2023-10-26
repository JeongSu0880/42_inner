/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:40 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/26 21:42:16 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

static size_t	word_cnt(const char *trim, char c)
{
	size_t	iter;
	size_t	cnt;

	cnt = 0;
	iter = 0;
	while (*(trim + iter))
	{
		if (*(trim + iter) == c)
			cnt++;
		iter++;
	}
	return (cnt);
}

static void	word_alloc(char	**arr, char *s, char c, size_t words)
{
	size_t	word_len;
	size_t	word_index;
	char	*s_start;

	word_index = 0;
	s_start = s;
	while (word_index < words)
	{
		word_len = ft_strchr(s_start, c) - s_start;
		ft_substr(*(arr + word_index), s_start - s, word_len);
		s_start = ft_strchr(s_start + 1, c);
		word_index++;
	}
	*(arr + words) = NULL;
}

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
	//	*result = s_trim;
	//	*(result + 1) = NULL;
		*result = s_trim;
		return (result);
	}
	iter = 0;
	words_size = word_cnt(s_trim, c);
	result = (char **)malloc(sizeof(char) * (words_size + 1));
	if (result == NULL)
		return (0);
	word_alloc(result, s_trim, c, words_size + 1);
	return (result);
}
