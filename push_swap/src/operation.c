/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:20:32 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/24 16:43:05 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*front;
	t_list	*back;

	if (stack->size < 2)
		return ;
	front = stack->top;
	back = stack->top->next;
	front->next = back->next;
	if (back->next != NULL)
		back->next->prev = front;
	back->next = front;
	front->prev = back;
	back->prev = NULL;
	stack->top = back;
	if (stack->size == 2)
		stack->rear = front;
}

void	push(t_stack *src, t_stack *dest)
{
	t_list	*moved;

	if (src->size == 0)
		return ;
	moved = src->top;
	moved->prev = NULL;
	src->top->prev = NULL;
	src->top = moved->next;
	src->size--;
	if (src->size == 0)
		src->rear = NULL;
	if (dest->top != NULL)
		dest->top->prev = moved;
	moved->next = dest->top;
	dest->top = moved;
	if (dest->size == 0)
		dest->rear = moved;
	dest->size++;
}

void	rotate(t_stack *stack)
{
	t_list	*moved;

	if (stack->size < 2)
		return ;
	moved = stack->top;
	stack->top = moved->next;
	stack->rear->next = moved;
	moved->prev = stack->rear;
	stack->rear = moved;
	moved->next = NULL;
}

void	r_rotate(t_stack *stack)
{
	t_list	*moved;
	t_list	*before_rear;
	int		i;

	i = 1;
	if (stack->size < 2)
		return ;
	moved = stack->rear;
	before_rear = stack->rear->prev;
	before_rear->next = NULL;
	moved->next = stack->top;
	moved->prev = NULL;
	stack->top->prev = moved;
	stack->rear = before_rear;
	stack->top = moved;
}

int	write_operation(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strcmp(operation, "sa\n") || ft_strcmp(operation, "ss\n"))
		swap(a);
	if (ft_strcmp(operation, "sb\n") || ft_strcmp(operation, "ss\n"))
		swap(b);
	if (ft_strcmp(operation, "pa\n"))
		push(b, a);
	if (ft_strcmp(operation, "pb\n"))
		push(a, b);
	if (ft_strcmp(operation, "ra\n") || ft_strcmp(operation, "rr\n"))
		rotate(a);
	if (ft_strcmp(operation, "rb\n") || ft_strcmp(operation, "rr\n"))
		rotate(b);
	if (ft_strcmp(operation, "rra\n") || ft_strcmp(operation, "rrr\n"))
		r_rotate(a);
	if (ft_strcmp(operation, "rrb\n") || ft_strcmp(operation, "rrr\n"))
		r_rotate(b);
	write(1, operation, ps_strlen(operation));
	return (1);
}
