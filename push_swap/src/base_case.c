/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:23:41 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 19:20:09 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_stack *stack, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (i < size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check_reverse_sort(t_stack *stack, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (i < size - 1)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	two_value_stack(t_stack *stack, char name)
{
	t_list	*prev;
	t_list	*next;

	prev = stack->top;
	next = prev->next;
	if (name == 'a' && prev->content > next->content)
		write_operation("sa\n", stack, NULL);
	if (name == 'b' && prev->content < next->content)
		write_operation("sb\n", NULL, stack);
	return (0);
}

int	three_value_stack_a(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack->top;
	second = first->next;
	if (first->content > second->content)
		write_operation("sa\n", stack, NULL);
	if (check_sort(stack, 3) == 0)
	{
		write_operation("ra\n", stack, NULL);
		write_operation("sa\n", stack, NULL);
		write_operation("rra\n", stack, NULL);
	}
	if (check_sort(stack, 3) == 0)
		write_operation("sa\n", stack, NULL);
	return (0);
}

int	three_value_stack_b(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack->top;
	second = first->next;
	if (first->content < second->content)
		write_operation("sb\n", NULL, stack);
	if (check_reverse_sort(stack, 3) == 0)
	{
		write_operation("rb\n", NULL, stack);
		write_operation("sb\n", NULL, stack);
		write_operation("rrb\n", NULL, stack);
	}
	if (check_reverse_sort(stack, 3) == 0)
		write_operation("sb\n", NULL, stack);
	return (0);
}
