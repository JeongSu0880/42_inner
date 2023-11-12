/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:22:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/12 13:04:58 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**p_new_list;
	t_list	*add_node;
	t_list	*now_pointer;

	p_new_list = &new_list;
	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	now_pointer = lst;
	while (now_pointer != NULL)
	{
		add_node = (t_list *)malloc(sizeof(t_list));
		if (add_node == NULL)
		{
			ft_lstclear(p_new_list, del);
			return (NULL);
		}
		add_node->content = f(now_pointer->content);
		add_node->next = NULL;
		ft_lstadd_back(p_new_list, add_node);
		now_pointer = now_pointer->next;
	}
	return (new_list);
}
// #include <stdio.h>
//
// int main()
// {
// 	t_list	*lst;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	**head;
// 	t_list	*new_list;
//
// 	head = &lst;
// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node1->content = "1";
// 	node2->content = "2";
//	
// 	lst = node1;
// 	node1->next = node2;
// 	node2->next = NULL;
// 	//new_list = ft_lstmap(new);
//
// 	free(node1);
// 	free(node2);
// }
