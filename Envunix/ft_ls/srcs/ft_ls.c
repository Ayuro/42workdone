/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:14:00 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/13 13:14:03 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_flags		flags;
	t_maxl		*maxl;
	t_diser		*args;

	ft_bzero(&flags, sizeof(t_flags));
	maxl = ft_memalloc(sizeof(t_maxl));
	args = ft_memalloc(sizeof(t_diser));
	get_args(ac, av, args);
	if (!init_flags(args, "-1AFRafilogprt", &flags))
		return (0);
	if (!check_empty(ac, av))
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		return (0);
	}
	if (!args->iargs)
		args->iargs = add_args(args->iargs, new_args(".", 0));
	parse_args(args, &flags);
	print_error(args->error);
	print_final(args->file, &flags, maxl, 2);
	print_final(args->dir, &flags, maxl, 3);
	return (0);
}
