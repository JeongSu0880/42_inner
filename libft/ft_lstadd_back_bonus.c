/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:32 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/09 18:59:32 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add_pointer;

	if (new == NULL)
		return ;
	if (lst == NULL || *lst == NULL)
	{
		lst = &new;
		new->next = NULL;
		return ;
	}
	add_pointer = ft_lstlast(*lst);
	add_pointer->next = new;
}
/*
#include	<stdio.h>

int main()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*lst;
	t_list	**p_lst;

	p_lst = &lst;
	node1->content = "1";
	node2->content = "2";
	node3->content = "3";
	node4->content = "4";

	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	ft_lstadd_back(&lst, node4);
	while (lst->next != NULL)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
}
*/
