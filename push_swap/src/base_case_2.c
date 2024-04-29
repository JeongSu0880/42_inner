/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:01:55 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 20:55:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_oper_cnt(t_cnt *oper)
{
	oper->part_1 = 0;
	oper->part_2 = 0;
	oper->part_3 = 0;
	oper->piv_1 = 0;
	oper->piv_2 = 0;
}

int	base_case_a(int size, t_stack *a)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		two_value_stack(a, 'a');
		return (1);
	}
	if (size == 3)
	{
		three_value_stack_a(a);
		return (1);
	}
	return (1);
}

int	base_case_b(int size, t_stack *a, t_stack *b)
{
	if (check_reverse_sort(b, size))
		return (operation_and_count("pa\n", size, a, b));
	if (size <= 1)
		return (operation_and_count("pa\n", 1, a, b));
	if (size == 2)
	{
		two_value_stack(b, 'b');
		return (operation_and_count("pa\n", 2, a, b));
	}
	if (size == 3)
	{
		three_value_stack_b(b);
		return (operation_and_count("pa\n", 3, a, b));
	}
	return (0);
}
