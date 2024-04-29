/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:16:37 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/28 19:51:54 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_num(char *nbr)
{
	int	i;

	i = 0;
	if ((nbr[i] == '+' || nbr[i] == '-') && nbr[i + 1] == '\0')
		return (0);
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr != NULL && nbr[i] != '\0')
	{
		if (ft_isdigit(nbr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *nbr, long long content)
{
	if (ft_strlen(nbr) > 11)
		return (0);
	if ((2147483647 < content) || (content < -2147483648))
		return (0);
	return (1);
}

int	is_already_in(int content, t_stack *a)
{
	t_list	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->content == content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_new_num(char *nbr, t_stack *a)
{
	t_list		*new;
	long long	content;

	if (is_num(nbr) == 0)
		handle_error("Error\n");
	content = ft_atoi(nbr);
	if (is_int(nbr, content) == 0)
		handle_error("Error\n");
	if (is_already_in((int)content, a) == 1)
		handle_error("Error\n");
	new = ft_lstnew((int)content);
	if (new == NULL)
		handle_error("Error\n");
	ft_lstadd_back(&(a->top), new);
	if (a->size == 0)
		a->top = new;
	a->rear = new;
	a->size++;
}

void	fill_stack_a(int argc, char *argv[], t_stack *a)
{
	int		i;
	int		j;
	char	**tmp;

	if (argc < 2)
		sort_already("");
	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		if (tmp == NULL)
			handle_error("Error\n");
		if (*tmp == NULL)
			handle_error("Error\n");
		while (tmp[j] != NULL)
		{
			add_new_num(tmp[j], a);
			free(tmp[j]);
			j++;
		}
		free(tmp);
		i++;
	}
}
