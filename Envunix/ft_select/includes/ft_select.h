/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:03:46 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:04:32 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
*** SYSTEM LIBRARIES
*/
# include <term.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

/*
*** LIBFT
*/
# include "../libft/includes/libft.h"

/*
*** MACROS
*/
# define MY_SP			32
# define MY_BSP			127
# define MY_UP			65
# define MY_DN			66
# define MY_RGT			67
# define MY_LFT			68
# define GO_HO			96

/*
*** DATA STRUCTURE AND GLOBAL VARIABLES
*/
typedef struct	s_select
{
	char						*name;
	int							print;
	int							select;
	struct s_select	*nxt;
	struct s_select	*prv;
}								t_select;

typedef struct	s_display
{
	int							row_h;
	int							print_nb;
	int							win_w;
	int							win_h;
	int							col_w;
	int							col_nb;
	int							small;
	t_select				*fst;
	t_select				*current;
	char						*search;
}								t_display;

typedef struct termios	t_termios;

typedef struct winsize	t_winsize;

t_display					*g_tty_info;

/*
*** SIGNAL FUNCTIONS
*/
int						catch_key(t_display *tty_info);
int						find_syntax(char *c, t_display *tty_info);
void					move_cursor(int key, t_display *tty_info);
void					update_lst(int key, t_display *tty_info);
void					signal_handler(int c);

/*
*** DISPLAY FUNCTIONS
*/
void					display_search(t_display *tty_info);
void					final_display(t_display *tty_info);
void					print_lst(t_display *tty_info, t_select *fst);
int						print_current(t_select *travel, int tcol, int trow);
int						print_select(t_select *travel, int tcol, int trow);
int						print_simple(t_select *travel, int tcol, int trow);
int						t_display_update(t_display *tty_info);
t_display			*t_display_init(t_select *fst);

/*
*** DATA FUNCTION PROTOTYPES
*/
void					free_lst(t_select *fst);
t_select			*put_to_lst(char **av, int ac);
t_select			*t_select_init(char *name, t_select *prev);
void					t_display_free(t_display *tty_info);

/*
*** TERMINAL FUNCTION PROTOTYPES
*/
void					ft_clear_term(void);
int						ft_init_term(struct termios *term, char *ttyname);
int						ft_set_term(struct termios *term);
int						ft_unset_term(struct termios *term);
int						ft_outc(int c);

#endif
