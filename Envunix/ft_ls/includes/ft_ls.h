/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 12:43:58 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/20 16:08:13 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
*** Includes
*/

# include "../libft/includes/libft.h"

/*
*** Macros
*/

# define MINORBITS		20
# define MINORMASK		((1U << MINORBITS) - 1)
# define MAJOR(dev)		((unsigned int) ((dev) >> MINORBITS))
# define MINOR(dev)		((unsigned int) ((dev) & MINORMASK))
# define S_IFWHT		0160000
# define S_ISWHT(m)		(((m) & S_IFMT) == S_IFWHT)
# define C_FILE			"\033[32m"
# define C_EXE			"\033[33m"
# define C_DIR			"\033[34m"
# define C_CLEAR		"\033[0m"

/*
*** Structures
*/

typedef struct			s_diser
{
	struct s_flist		*iargs;
	struct s_flist		*error;
	struct s_flist		*file;
	struct s_flist		*dir;
}						t_diser;

typedef struct			s_flist
{
	char				*dname;
	time_t				mtime;
	struct s_flist		*next;
}						t_flist;

typedef struct			s_flags
{
	int					ua;
	int					uf;
	int					ur;
	int					a;
	int					r;
	int					t;
	int					f;
	int					p;
	int					o;
	int					g;
	int					i;
	int					l;
	int					one;
	int					nfirst;
	int					count;
	int					error;
}						t_flags;

typedef struct			s_maxl
{
	int					uid;
	int					gid;
	int					ino;
	int					size;
	int					masize;
	int					links;
	unsigned long		nblocks;
	int					total;
}						t_maxl;

typedef struct			s_fdata
{
	char				*dname;
	char				*path;
	char				*ouid;
	char				*ogid;
	off_t				size;
	dev_t				rdev;
	nlink_t				nlinks;
	char				*mode;
	ino_t				ino;
	time_t				atime;
	time_t				mtime;
	time_t				nsec;
	char				*smtime;
	struct s_fdata		*next;
}						t_fdata;

/*
*** args_tools.c
*/

void					get_args(int ac, char **av, t_diser *args);
t_flist					*new_args(char *name, time_t time);
t_flist					*add_args(t_flist *list, t_flist *elem);
void					fill_args(t_diser *args, t_flist *elem, int type);
void					sort_args(t_diser *args, t_flist *elem, int type, \
	t_flags *flags);

/*
*** args_tools2.c
*/

t_flist					*args_insort(t_flist *fdata, t_flist *elem, \
	t_flags *flgs);
int						scmp(char *a, char *b);
int						intcmp(long a, long b, t_flags *flags);

/*
*** flags.c
*/

int						init_flags(t_diser *args, char *leg, t_flags *flags);
void					get_flags(int opt, t_flags *flags);
void					get_flags_bis(int opt, t_flags *flags);

/*
*** parsing.c
*/

int						check_empty(int ac, char **av);
void					parse_args(t_diser *args, t_flags *flags);
void					get_error(t_flist *elem, t_diser *args, t_flags *flags);

/*
*** print.c
*/

void					print_error(t_flist *list);
int						print_final(t_flist *list, t_flags *flags, \
	t_maxl *maxl, int type);

/*
*** create_list.c
*/

void					create_list(char *dname, t_flags *fl, t_maxl *maxl, \
	int t);
void					put_dname(char *dname, t_flags *fl);

/*
*** fdatanew.c
*/

t_fdata					*fdatanew(char *dname, char *fname, t_flags *fl, \
	t_maxl *maxl);
char					*get_path(char *dst, char *src);
void					get_data(struct stat dstat, t_fdata *elem, \
	t_maxl *maxl);
void					get_long_data(struct stat dstat, t_fdata *elem, \
	t_maxl *maxl);

/*
*** fget_data.c
*/

char					*get_attr(char *ret, char *dname);
char					*get_type(char *ret, mode_t mode);
char					*get_mode(mode_t mode);
void					get_uid(uid_t st_uid, gid_t st_gid, t_fdata *fdata);
void					get_time(t_fdata *fdata);

/*
*** list_tools.c
*/

t_fdata					*get_list(char *dname, t_flags *fl, t_maxl *maxl);
char					*get_fname(char *str);
t_fdata					*lst_add(t_fdata *fdata, t_fdata *elem);
t_fdata					*lst_insort(t_fdata *fdata, t_fdata *elem, t_flags *fl);
t_fdata					*lst_insert(t_fdata *prev, t_fdata *new, t_fdata *lst, \
	t_fdata *tmp);

/*
*** print_tools.c
*/

t_fdata					*print_list(t_fdata *fdata, t_flags *flags, \
	t_maxl *maxl);
void					print_long(t_fdata *fdata, t_maxl *maxl, \
	t_flags *flags);
void					append_type(t_fdata *fdata, t_flags *flags);
void					print_ino(t_fdata *fdata, t_maxl *maxl, \
	t_flags *flags);
void					color(t_fdata *fdata);

/*
*** print_tools2.c
*/

void					putlink(char *str);
void					put_majmin(dev_t rdev, t_maxl *maxl);
void					put_padded(char *str, int nbr, int width);

#endif
