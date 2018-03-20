/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:42:28 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:42:42 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
*** INCLUDES
*/

# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

/*
***	MACROS
*/

# ifndef SUCCESS
#  define SUCCESS		1
# endif
# ifndef FAILURE
#  define FAILURE		0
# endif
# ifndef TRUE
#  define TRUE			1
# endif
# ifndef FALSE
#  define FALSE			0
# endif

# define RET_OK			0
# define RET_FAIL		-1

# define ABS(a)			(a < 0 ? -a : a)
# define MIN(a, b)		(a <= b ? a : b)
# define MAX(a, b)		(a >= b ? a : b)

/*
*** STRUCT;
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
*** TYPEDEF;
*/

typedef char			t_bool;
typedef char			t_iny;

/*
*** PROTOS
*/

/*
** Display
*/

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int nb, int base);
void				ft_putnbr_base_chrs(int nb, char *base);
void				ft_putnbr_l_base(long nb, int base);
void				ft_putnbr_l_base_chrs(long nb, char *base);
void				ft_putnbr_lu_base(unsigned long nb, int base);
void				ft_putnbr_lu_base_chrs(unsigned long nb, char *base);
void				ft_putnbr_u_base(unsigned int nb, int base);
void				ft_putnbr_u_base_chrs(unsigned int nb, char *base);

/*
** Char analysis & Modif
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_nbrlen_base(int nb, int base);
void				ft_putnbr_base(int nb, int base);

/*
** Nbr analysis & Modif
*/

int					ft_nbrlen_base(int nb, int base);
int					ft_nbrlen_base_chrs(long int nb, char *base);
int					ft_nbrlen_l(long nb);
int					ft_nbrlen_l_base(long nb, int base);
int					ft_nbrlen_l_base_chrs(long nb, char *base);
int					ft_nbrlen_lu(unsigned long nb);
int					ft_nbrlen_lu_base(unsigned long nb, int base);
int					ft_nbrlen_lu_base_chrs(unsigned long nb, char *base);
int					ft_nbrlen_u(unsigned int nb);
int					ft_nbrlen_u_base(unsigned int nb, int base);
int					ft_nbrlen_u_base_chrs(unsigned int nb, char *base);

/*
** Str analysis & Modif
*/

void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strrev(char *str);
int					ft_nbrlen(long int nb);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

/*
** Mem analysis & Modif
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** List analysis & Modif
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint_str(t_list **list, char c);
int					ft_lstsize(t_list *alst);
t_list				*ft_lstelem(t_list *begin_list, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);

/*
** Printf function
*/

int					ft_printf(const char *format, ...);
int					ft_printf_b(void *c);
int					ft_printf_bu(void *c);
int					ft_printf_c(void *c);
int					ft_printf_i(void *c);
int					ft_printf_lb(void *c);
int					ft_printf_lbu(void *c);
int					ft_printf_li(void *c);
int					ft_printf_lo(void *c);
int					ft_printf_lu(void *c);
int					ft_printf_lx(void *c);
int					ft_printf_lxu(void *c);
int					ft_printf_o(void *c);
int					ft_printf_p(void *c);
int					ft_printf_pu(void *c);
int					ft_printf_s(void *c);
int					ft_printf_u(void *c);
int					ft_printf_x(void *c);
int					ft_printf_xu(void *c);

/*
** Get Next Line
*/

int					get_next_line(const int fd, char **line);

#endif
