/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:20:32 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/24 16:45:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_bonus(t_stack *stack, int *flag)
{
	t_list	*front;
	t_list	*back;

	*flag = 1;
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

void	push_bonus(t_stack *src, t_stack *dest, int *flag)
{
	t_list	*moved;

	*flag = 1;
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

void	rotate_bonus(t_stack *stack, int *flag)
{
	t_list	*moved;

	*flag = 1;
	if (stack->size < 2)
		return ;
	moved = stack->top;
	stack->top = moved->next;
	stack->rear->next = moved;
	moved->prev = stack->rear;
	stack->rear = moved;
	moved->next = NULL;
}

void	r_rotate_bonus(t_stack *stack, int *flag)
{
	t_list	*moved;
	t_list	*before_rear;
	int		i;

	*flag = 1;
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

void	handle_operation(char *operation, t_stack *a, t_stack *b)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(operation, "sa\n") || ft_strcmp(operation, "ss\n"))
		swap_bonus(a, &flag);
	if (ft_strcmp(operation, "sb\n") || ft_strcmp(operation, "ss\n"))
		swap_bonus(b, &flag);
	if (ft_strcmp(operation, "pa\n"))
		push_bonus(b, a, &flag);
	if (ft_strcmp(operation, "pb\n"))
		push_bonus(a, b, &flag);
	if (ft_strcmp(operation, "ra\n") || ft_strcmp(operation, "rr\n"))
		rotate_bonus(a, &flag);
	if (ft_strcmp(operation, "rb\n") || ft_strcmp(operation, "rr\n"))
		rotate_bonus(b, &flag);
	if (ft_strcmp(operation, "rra\n") || ft_strcmp(operation, "rrr\n"))
		r_rotate_bonus(a, &flag);
	if (ft_strcmp(operation, "rrb\n") || ft_strcmp(operation, "rrr\n"))
		r_rotate_bonus(b, &flag);
	if (flag == 0)
		handle_error("Error\n");
}
