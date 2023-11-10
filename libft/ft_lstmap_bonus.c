/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:22:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/10 20:41:17 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	**p_new_list;
// 	t_list	*add_node;
// 	t_list	*now_pointer;

// 	p_new_list = &new_list;
// 	if (!lst || !f)
// 		return (NULL);
// 	now_pointer = lst;
// 	while (now_pointer != NULL)
// 	{
// 		add_node = (t_list *)malloc(sizeof(t_list));
// 		if (add_node == NULL)
// 		{
// 			ft_lstclear(p_new_list, del);
// 			return (NULL);
// 		}
// 		add_node->content = f(now_pointer->content);
// 		add_node->next = NULL;
// 		if (now_pointer == lst)
// 			new_list = add_node;
// 		ft_lstadd_back(p_new_list, add_node);
// 		now_pointer = now_pointer->next;
// 	}
// 	return (new_list);
// }

// #include <stdio.h>

// int main()
// {
// 	t_list *add_node;
// 	t_list *lst;
// 	t_list **head;

// 	head = &lst;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		add_node = (t_list *)malloc(sizeof(t_list));
// 		add_node->content = (char *)i;
// 		add_node->next = NULL;
// 		ft_lstadd_back(head, add_node);
// 	}
// 	printf("size %d\n", ft_lstsize(lst));

// 	t_list *free_node = lst;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		t_list *tmp = free_node->next;
// 		free(free_node);
// 		free_node = tmp;
// 	}
// }
//
#include <stdio.h>

int main()
{
	int		idx;
	int		len;
	t_list	*new_list;
	t_list	**p_new_list;
	t_list	*add_node;
	t_list	*now_pointer;
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	**head;

	head = &lst;
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node1->content = "1";
	node2->content = "2";
	
	ft_lstadd_back(head, node1);
	ft_lstadd_back(head, node2);

	if (ft_lstlast(*head)->next == NULL)
		printf("kkk");

	idx = 0;
	len = ft_lstsize(lst);

	p_new_list = &new_list;
	printf("size %d\n", len);
	now_pointer = lst;
	printf("size %d\n", len);
	while (idx < 2)
	{
		add_node = (t_list *)malloc(sizeof(t_list));
		add_node->content = "lllkjlkjlkjlkjlkjljlkjlkjljlj\n";
		add_node->next = NULL;
		// printf("here??????");
		if (idx == 0)
			new_list = add_node;
		if (ft_lstlast(*p_new_list)->next == NULL)
			printf("나나 \n");
		ft_lstadd_back(p_new_list, add_node);
		if (add_node->next == NULL)
			printf("glgl \n");
		now_pointer = now_pointer->next;
		idx++;
	}
	len = ft_lstsize(new_list);
	printf("size %d\n", len);
	while (new_list != NULL)
	{
		printf("%s\n", new_list->content);
		new_list = new_list->next;
	}
	free(node1);
	free(node2);
}