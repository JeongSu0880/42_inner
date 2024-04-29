/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:11:11 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 20:56:24 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_a_not_reverse(t_stack *a, t_stack *b, t_cnt *oper, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->top->content <= oper->piv_1)
		{
			operation_and_count("pb\n", 1, a, b);
			oper->part_1 += operation_and_count("rb\n", 1, a, b);
		}
		else if (a->top->content <= oper->piv_2)
			oper->part_2 += operation_and_count("pb\n", 1, a, b);
		else
			oper->part_3 += operation_and_count("ra\n", 1, a, b);
		i++;
	}
}

int	start_sort(t_stack *a, t_stack *b)
{
	t_cnt	oper;

	ft_memset(&oper, 0, sizeof(t_cnt));
	if (a->size == 1 || a->size == 2 || a->size == 3)
		return (base_case_a(a->size, a));
	get_pivot_a(a, a->size, &(oper.piv_1), &(oper.piv_2));
	check_a_not_reverse(a, b, &oper, a->size);
	a_to_b(a, b, oper.part_3);
	b_to_a(a, b, oper.part_2);
	b_to_a(a, b, oper.part_1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	fill_stack_a(argc, argv, &a);
	if (check_sort(&a, a.size))
		sort_already("");
	if (a.size == 3)
		input_3(&a);
	else if (a.size == 5)
		input_5(&a, &b);
	else
		start_sort(&a, &b);
	exit(0);
}
