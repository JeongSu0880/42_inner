/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:22:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/08 20:55:25 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**head;
	t_list	*new_list;
	t_list	*add_node;
	t_list	*lst_tmp;

	lst_tmp = lst;
	head = &new_list;
	while (lst_tmp->next != NULL)
	{
		add_node = (t_list *)malloc(sizeof(t_list));
		if (add_node == NULL && new_list != NULL)
			ft_lstclear(head, del);
		add_node->content = f(lst_tmp->content);
		lst_tmp = lst_tmp->next;
		ft_lstadd_back(head, add_node);
	}
	return (new_list);
}
