/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:57 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/12 12:57:56 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_pointer;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	del_pointer = *lst;
	while (del_pointer != NULL)
	{
		tmp = del_pointer->next;
		ft_lstdelone(del_pointer, del);
		del_pointer = tmp;
	}
	*lst = NULL;
}
