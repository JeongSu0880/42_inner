/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:20:56 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/09 18:34:58 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pointer;
	int		node_cnt;

	if (lst == NULL)
		return (0);
	node_cnt = 0;
	pointer = lst;
	while (pointer->next != NULL)
	{
		node_cnt++;
		pointer = pointer->next;
	}
	node_cnt++;
	return (node_cnt);
}
/*
#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{
	t_list	*lst;
	t_list	*pointer = lst;
	lst = (t_list *)malloc(sizeof(t_list) * 3);
	for (int i = 0; i < 3; i++)
	{
		pointer->content = i;
		pointer->next = 
	}
}
*/
