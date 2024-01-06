/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:32 by jungslee          #+#    #+#             */
/*   Updated: 2024/01/05 17:01:09 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_len
{
    int nl;
    int len_sum;
}   t_len;

typedef struct s_buf
{
	ssize_t	read_len;
	char	buf[BUFFER_SIZE];
}	t_buf;

typedef struct s_fd
{
    struct s_fd    *front;
    struct s_fd    *back;
    int     fd;
    char    *rest;
}   t_fd;

// ssize_t	gnl_strlen(const char *str);
// char	*gnl_strdup(const char *s);
// char	*gnl_strnjoin(char *s1, char *s2, ssize_t idx);
// char	*error_free(char **buf);
// ssize_t	check_nl(char *buf, ssize_t len, ssize_t *nl_idx);
// char	*renew(char *original, char *src, ssize_t idx, char *to_free);
// char	*sub_sur(char *surplus, ssize_t nl_idx, char *to_free);
// ssize_t	while_surplus(char **res, char **surplus, ssize_t *nl_idx);
// ssize_t	while_read(t_buf unit, char **res, char **surplus, ssize_t *nl_idx);
// char	*get_next_line(int fd);

#endif
