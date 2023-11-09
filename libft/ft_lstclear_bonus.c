/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:21:57 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/08 20:36:29 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		idx;
	int		len;
	t_list	*del_pointer;
	t_list	*tmp;

	len = ft_lstsize(*lst);
	del_pointer = *lst;
	idx = 0;
	while (idx < len)
	{
		tmp = del_pointer->next;
		ft_lstdelone(del_pointer, del);
		del_pointer = tmp;
		idx++;
	}
	lst = NULL;
}
