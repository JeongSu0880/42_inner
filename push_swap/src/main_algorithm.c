/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:17:57 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 20:56:18 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operation_and_count(char *operation, int count, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write_operation(operation, a, b);
		i++;
	}
	return (count);
}

void	check_a(t_stack *a, t_stack *b, t_cnt *oper, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->top->content <= oper->piv_1)
			oper->part_1 += operation_and_count("pb\n", 1, a, b);
		else if (a->top->content <= oper->piv_2)
		{
			operation_and_count("pb\n", 1, a, b);
			oper->part_2 += operation_and_count("rb\n", 1, a, b);
		}
		else
			oper->part_3 += operation_and_count("ra\n", 1, a, b);
		i++;
	}
}

void	check_b(t_stack *a, t_stack *b, t_cnt *oper, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (b->top->content <= oper->piv_1)
			oper->part_1 += operation_and_count("rb\n", 1, a, b);
		else if (b->top->content <= oper->piv_2)
		{
			operation_and_count("pa\n", 1, a, b);
			oper->part_2 += operation_and_count("ra\n", 1, a, b);
		}
		else
			oper->part_3 += operation_and_count("pa\n", 1, a, b);
		i++;
	}
}

int	a_to_b(t_stack *a, t_stack *b, int size)
{
	t_cnt	oper;

	ft_memset(&oper, 0, sizeof(t_cnt));
	if (size == 1 || size == 2 || size == 3)
		return (base_case_a(size, a));
	get_pivot_a(a, size, &(oper.piv_1), &(oper.piv_2));
	check_a(a, b, &oper, size);
	operation_and_count("rrr\n", oper.part_2, a, b);
	a_to_b(a, b, oper.part_3);
	b_to_a(a, b, oper.part_2);
	b_to_a(a, b, oper.part_1);
	return (1);
}

int	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_cnt	oper;

	init_oper_cnt(&oper);
	ft_memset(&oper, 0, sizeof(t_cnt));
	if (size == 1 || size == 2 || size == 3)
		return (base_case_b(size, a, b));
	get_pivot_b(b, size, &(oper.piv_1), &(oper.piv_2));
	check_b(a, b, &oper, size);
	a_to_b(a, b, oper.part_3);
	operation_and_count("rrr\n", oper.part_2, a, b);
	a_to_b(a, b, oper.part_2);
	b_to_a(a, b, oper.part_1);
	return (1);
}
