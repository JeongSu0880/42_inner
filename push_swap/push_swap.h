/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:49:32 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 20:56:09 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	t_list	*rear;
	int		size;
}	t_stack;

typedef struct s_cnt
{
	int	part_1;
	int	part_2;
	int	part_3;
	int	piv_1;
	int	piv_2;
}	t_cnt;

void	handle_error(char *str);
void	sort_already(char *str);
void	init_stack(t_stack *stack);
int		ps_strlen(char *str);
void	fill_stack_a(int argc, char *argv[], t_stack *a);
void	handle_operation(char *operation, t_stack *a, t_stack *b);
int		ft_strcmp(char *s1, char *s2);
int		detect_oper(char *oper1, char *oper2, char *operation);
void	get_pivot_a(t_stack *stack, int size, int *p1, int *p2);
void	get_pivot_b(t_stack *stack, int size, int *p1, int *p2);
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);
void	swap_bonus(t_stack *stack, int *flag);
void	push_bonus(t_stack *src, t_stack *dest, int *flag);
void	rotate_bonus(t_stack *stack, int *flag);
void	r_rotate_bonus(t_stack *stack, int *flag);
void	swap_and_write(t_stack *a, t_stack *b, char name, int *cnt);
void	push_and_write(t_stack *src, t_stack *dest, char dest_name, int *cnt);
void	rotate_and_write(t_stack *a, t_stack *b, char name, int *cnt);
void	r_rotate_and_write(t_stack *a, t_stack *b, char name);
int		a_to_b(t_stack *a, t_stack *b, int size);
int		b_to_a(t_stack *a, t_stack *b, int size);
int		write_operation(char *operation, t_stack *a, t_stack *b);
int		check_sort(t_stack *stack, int size);
int		check_reverse_sort(t_stack *stack, int size);
int		three_value_stack_b(t_stack *stack);
int		three_value_stack_a(t_stack *stack);
void	check_a(t_stack *a, t_stack *b, t_cnt *oper, int size);
void	input_3(t_stack *stack);
int		two_value_stack(t_stack *stack, char name);
void	selection_sort(int *arr, int size);
void	copy_stack(int *arr, t_stack *stack, int size);
int		operation_and_count(char *operation, int count, t_stack *a, t_stack *b);
void	input_5(t_stack *a, t_stack *b);
void	init_oper_cnt(t_cnt *oper);
int		base_case_b(int size, t_stack *a, t_stack *b);
int		base_case_a(int size, t_stack *a);
int		get_pivot_single(t_stack *stack, int size);

#endif