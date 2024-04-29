/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:18:09 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 19:37:04 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	sort_already(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (*(str1 + i) != '\0' || *(str2 + i) != '\0')
	{
		if (*(str1 + i) != *(str2 + i))
			return (0);
		i++;
	}
	return (1);
}

int	ps_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}
