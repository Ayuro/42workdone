/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:16:14 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:16:36 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

# define FLAG_MIN 1
# define FLAG_PLU 2
# define FLAG_SPC 4
# define FLAG_DSH 8
# define FLAG_ZRO 16


typedef struct s_opt	t_opt;

typedef int				(*fn_spc)(va_list, t_opt);

struct			s_opt
{
	int			flg;
	int			wdt;
	int			prc;
	int			len;
	fn_spc		spc;
	char		ch;
};


/*
** mainf.c
*/

int		ft_printf(const char *fmt, ...);
int		pf_parser(char **ptr, va_list ap);

/*
**  parser.c
*/

int		pf_flag(char *fmt, int i, t_opt *opt);
int		pf_width(char *fmt, int i, t_opt *opt, va_list ap);
int		pf_precision(char *fmt, int i, t_opt *opt, va_list ap);
int		pf_length(char *fmt, int i, t_opt *opt);
int		pf_specifier(char *fmt, int i, t_opt *opt);

/*
** function.c
*/

fn_spc	pf_spc_fn(int i);
int		pf_spc_nop(va_list list, t_opt opt);
int		pf_spc_int(va_list list, t_opt opt);
int		ft_total_len(long long int n, int baselen, t_opt opt);
char	*ft_int_to_base(long long int n, char *base, t_opt opt);


/*
** function2.c
*/

int		pf_spc_uint(va_list list, t_opt opt);
int		pf_spc_uint_bin(va_list list, t_opt opt);
int		pf_spc_uint_oct(va_list list, t_opt opt);
int		pf_spc_uint_hex(va_list list, t_opt opt);
int		pf_spc_uint_hxx(va_list list, t_opt opt);

/*
** function3.c
*/

int		ft_utotal_len(unsigned long long int n, int baselen, t_opt opt);
char	*ft_uint_to_base(unsigned long long int n, char *base, t_opt opt);
int		pf_spc_char(va_list list, t_opt opt);
int		pf_spc_str(va_list list, t_opt opt);
int		pf_spc_ptr(va_list list, t_opt opt);

/*
** tools.c
*/

int		ft_putnchar(char c, int n);
int		ft_strlen(char *str);
int		ft_nbrlen_base(long long int n, int baselen);
int		ft_atoi(const char *str);


#endif
