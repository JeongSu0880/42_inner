/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:15 by jungslee          #+#    #+#             */
/*   Updated: 2024/04/17 17:08:39 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_buf
{
	ssize_t	read_len;
	char	buf[BUFFER_SIZE];
}	t_buf;

typedef struct s_fd
{
	struct s_fd	*front;
	struct s_fd	*back;
	int			fd;
	char		*rest;
}	t_fd;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *ptr, int value, size_t num);
void		ft_bzero(void *ptr, size_t num);
void		*ft_memcpy(void *dest, const void *source, size_t num);
void		*ft_memmove(void *dest, const void *src, size_t num);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long long	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(int));
void		ft_lstclear(t_list **lst, void (*del)(int));
void		ft_lstiter(t_list *lst, void (*f)(int));
t_list		*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
int			check_buf(t_fd **fd_list, t_fd **now_fd, char **ret, t_buf unit);
int			gnl_sub_str(char **dest, char *str, int start, int end);
int			find_new_line(char *cp_buf, int cp_end, char **ret, t_fd *now_fd);
t_fd		*init_node(int fd, t_fd *front, t_fd *back);
int			gnl_strlen(char *str);
char		*get_next_line(int fd);
char		*del_file(t_fd **fd_node, t_fd **fd_list, char **ret);
int			renew_ret(char *buf, int cp_end, char **ret);
t_fd		*search_fd(t_fd **fd_list, int fd);
int			free_and_init(char **allocated, char *new, int return_vl);

#endif