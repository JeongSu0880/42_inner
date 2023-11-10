/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:20:37 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/10 17:16:49 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// #include	<stdio.h>
// int main()
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	**head;
// 	t_list	*lst;
//
// 	head = &lst;
// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node1->content = "1";
// 	node2->content = "2";
//	
// 	ft_lstadd_front(head, node1);
// 	ft_lstadd_front(head, node2);
// 	// ft_lstadd_back(&lst, &node2);
// 	// ft_lstadd_back(&lst, &node3);
// 	// ft_lstadd_back(&lst, &node4);
// 	while (lst != NULL)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// 	free(node1);
// 	free(node2);
// }