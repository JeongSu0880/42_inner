/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:36:46 by jungslee          #+#    #+#             */
/*   Updated: 2024/05/20 21:19:53 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef SLEEP
#  define SLEEP 100
# endif

typedef struct s_character
{
	char	c;
	int		uni_idx;
	char	uni_c[4];
	int		uni_byte;
	int		zero_flag;
	int		bits_num;
}	t_character;

typedef struct s_sig
{
	sig_atomic_t	bit;
	sig_atomic_t	pid;
	t_character		printable;
}	t_sig;

typedef struct s_sig_c
{
	sig_atomic_t	usr1;
	sig_atomic_t	usr2;
	sig_atomic_t	pid;
}	t_sig_c;

void		handle_error(char *str);
long long	ft_atoi(char *str);
int			pow_2(int num);
void		init_all(struct sigaction *sa);

#endif
