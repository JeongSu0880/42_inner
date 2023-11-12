/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:32 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/12 12:29:04 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add_pointer;

	if (!lst || !new)
		return ;
	if (ft_lstsize(*lst) == 0)
	{
		*lst = new;
		return ;
	}
	add_pointer = ft_lstlast(*lst);
	add_pointer->next = new;
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
// 	ft_lstadd_back(head, node1);
// 	ft_lstadd_back(head, node2);
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
