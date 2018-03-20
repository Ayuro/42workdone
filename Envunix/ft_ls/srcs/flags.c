/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:22:50 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/18 16:22:51 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_flags_bis(int opt, t_flags *flags)
{
	if (!flags->a)
	{
		flags->ua = (opt == 'A') ? 1 : flags->ua;
		flags->a = (opt == 'A') ? 1 : flags->a;
	}
	flags->ua = (opt == 'a') ? 0 : flags->ua;
	flags->a = (opt == 'a') ? 1 : flags->a;
	flags->ur = (opt == 'R') ? 1 : flags->ur;
	flags->r = (opt == 'r') ? 1 : flags->r;
	flags->i = (opt == 'i') ? 1 : flags->i;
	flags->o = (opt == 'o') ? 1 : flags->o;
	flags->l = (opt == 'o') ? 1 : flags->l;
	flags->g = (opt == 'g') ? 1 : flags->g;
	flags->l = (opt == 'g') ? 1 : flags->l;
	flags->t = (opt == 't') ? 1 : flags->t;
}

void	get_flags(int opt, t_flags *flags)
{
	get_flags_bis(opt, flags);
	if (flags->uf)
		flags->p = 0;
	flags->p = (opt == 'p') ? 1 : flags->p;
	if (flags->p)
		flags->uf = 0;
	flags->uf = (opt == 'F') ? 1 : flags->uf;
	if (flags->l)
		flags->one = 0;
	flags->one = (opt == '1') ? 1 : flags->one;
	if (flags->one)
		flags->l = 0;
	flags->l = (opt == 'l') ? 1 : flags->l;
	if (opt == 'f')
	{
		flags->f = 1;
		flags->a = 1;
		flags->ua = 0;
	}
}

int		init_flags(t_diser *args, char *leg, t_flags *flags)
{
	int		opt;
	int		i;

	while (args->iargs && args->iargs->dname[0] == '-' && !(i = 0))
	{
		while (args->iargs && (opt = ft_getopt(args->iargs->dname[++i], leg)))
		{
			if (opt == 'n')
				return (ft_usage("ft_ls", leg, args->iargs->dname[i]));
			if (opt == '-')
			{
				if (i != 1 || (i == 1 && args->iargs->dname[i + 1]))
					return (ft_usage("ft_ls", leg, args->iargs->dname[i]));
				args->iargs = args->iargs->next;
				return (1);
			}
			get_flags(opt, flags);
			if (getuid() == 0 && (flags->ua = 1))
				flags->a = 1;
		}
		if (i == 1)
			return (1);
		args->iargs = args->iargs->next;
	}
	return (1);
}
