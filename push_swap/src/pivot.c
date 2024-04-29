/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:48:13 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/25 00:22:23 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		min_idx = i;
		while (j < size)
		{
			if (arr[j] <= arr[min_idx])
				min_idx = j;
			j++;
		}
		tmp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = tmp;
		i++;
	}
}

void	copy_stack(int *arr, t_stack *stack, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top;
	while (i < size)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}

static void	decide_portion(int *one, int *same, int size)
{
	int	rest;

	rest = size % 3;
	if (rest == 0)
	{
		*same = size / 3;
		*one = *same;
	}
	if (rest == 1)
	{
		*same = size / 3;
		*one = size / 3 + 1;
	}
	if (rest == 2)
	{
		*same = size / 3 + 1;
		*one = size / 3;
	}
}

void	get_pivot_a(t_stack *stack, int size, int *p1, int *p2)
{
	int	*arr;
	int	same_portion;
	int	one_portion;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		handle_error("Error\n");
	copy_stack(arr, stack, size);
	selection_sort(arr, size);
	decide_portion(&one_portion, &same_portion, size);
	*p1 = arr[one_portion - 1];
	*p2 = arr[one_portion + same_portion - 1];
	free(arr);
}

void	get_pivot_b(t_stack *stack, int size, int *p1, int *p2)
{
	int	*arr;
	int	same_portion;
	int	one_portion;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		handle_error("Error\n");
	copy_stack(arr, stack, size);
	selection_sort(arr, size);
	decide_portion(&one_portion, &same_portion, size);
	*p1 = arr[same_portion - 1];
	*p2 = arr[same_portion * 2 - 1];
	free(arr);
}
