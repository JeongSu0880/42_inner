/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:22:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/17 21:44:19 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	int		idx;
	int		len;
	t_list	*f_pointer;

	idx = 0;
	f_pointer = lst;
	len = ft_lstsize(lst);
	while (idx < len)
	{
		f(f_pointer->content);
		f_pointer = f_pointer->next;
		idx++;
	}
}
