/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:16 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/12 12:58:27 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pointer;

	if (lst == NULL)
		return (NULL);
	pointer = lst;
	while (pointer->next != NULL)
		pointer = pointer->next;
	return (pointer);
}
