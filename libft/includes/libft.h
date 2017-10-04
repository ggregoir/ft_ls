/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:00:19 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/09/11 15:21:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

# define BUFF_SIZE 4096

# define EOC		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define HIGH		"\033[1m"

# define BG_RED		"\033[41m"
# define BG_BLUE	"\033[44m"

# define HRED		"\033[1m\033[31m"
# define HGREEN		"\033[1m\033[32m"
# define HYELLOW	"\033[1m\033[33m"
# define HBLUE		"\033[1m\033[34m"
# define HMAG		"\033[1m\033[35m"
# define HCYAN		"\033[1m\033[36m"

typedef unsigned char	t_byte;

typedef struct	s_list
{
	void				*data;
	size_t				size;
	struct s_list		*next;
}				t_list;

/*
** what it is
*/

int				ft_isupper(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** Memory
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_free_strsplit(char *s, char **buff, char split);
void			ft_free_grid(void ***grid);

/*
** Putin Сука Блять
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_print_memory(const void *addr, size_t size);
void			ft_color(char *color, char *str, char *end);
void			ft_colorendl(char *color, char *str, char *end);

/*
** Str
*/

char			*ft_strcat(char *dest, const char *src);
char			*ft_strcut(char *str, int start, int end);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinf(char const *s1, char const *s2, int flag);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str);
void			*ft_realloc(void *src, size_t srcsize, size_t newsize);
char			*ft_strcjoin(char *delim, char **arr, size_t size);
void			ft_printjoin(char *delim, char **arr, size_t size);
int				ft_count_words(const char *str, char c);
void			ft_error(char *message);

/*
** Conversions
*/

long			ft_atoi(const char *str);
char			*ft_itoa(int n);
long			ft_atol(const char *str);

/*
** List
*/

t_list			*ft_lstnew(void const *data, size_t size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelcont(t_list **alst, void *cont);
void			ft_lst_add_back(t_list **alst, t_list *new);

/*
** Get_next_line
*/

int				ft_gnl(const int fd, char **line);

typedef struct	s_gnl
{
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				ret;
}				t_gnl;

#endif
