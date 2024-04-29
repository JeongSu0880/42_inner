/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:53:51 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/29 15:22:54 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_array(t_stack stack)
{
	int		i;
	t_list	*tmp;

	if (stack.size < 2)
		return (1);
	i = 0;
	tmp = stack.top;
	while (i < stack.size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*operation;

	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	fill_stack_a(argc, argv, &a);
	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		handle_operation(operation, &a, &b);
		free(operation);
	}
	if (b.size > 0 || !(check_array(a)))
		write(1, "KO\n", 3);
	else if (check_array(a))
		write(1, "OK\n", 3);
	exit(0);
}
