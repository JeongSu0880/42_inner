/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:42:36 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 19:34:33 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_max(t_stack *stack, int num)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (i < stack->size)
	{
		if (tmp->content > num)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	input_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->content;
	second = stack->top->next->content;
	third = stack->rear->content;
	if (is_max(stack, second))
		write_operation("rra\n", stack, NULL);
	else if (is_max(stack, first))
		write_operation("ra\n", stack, NULL);
	if (!check_sort(stack, 3))
		write_operation("sa\n", stack, NULL);
}

int	get_pivot_single(t_stack *stack, int size)
{
	int	*arr;
	int	pivot;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		handle_error("Error\n");
	copy_stack(arr, stack, size);
	selection_sort(arr, size);
	pivot = arr[size / 2 - 1];
	free(arr);
	return (pivot);
}

void	input_5(t_stack *a, t_stack *b)
{
	int	pivot;
	int	cnt;

	cnt = 0;
	pivot = get_pivot_single(a, a->size);
	while (cnt < 2)
	{
		if (a->top->content > pivot)
			write_operation("ra\n", a, b);
		else
		{
			write_operation("pb\n", a, b);
			cnt++;
		}
	}
	input_3(a);
	two_value_stack(b, 'b');
	operation_and_count("pa\n", 2, a, b);
}
