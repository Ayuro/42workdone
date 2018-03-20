/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:59 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:59 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

t_optionset	*sg_opt(void)
{
	static t_optionset	*opt = NULL;

	if (opt == NULL)
	{
		if ((opt = (t_optionset *)malloc(sizeof(t_optionset))) == NULL)
			exit_failure_malloc();
		opt->colorset = OPT_CLSNONE;
		opt->colorstep = DEF_CLRSTEP;
		opt->rotation = OPT_ROTISO;
		opt->padding = DEF_PADDING;
		opt->screen_w = DEF_SC_W;
		opt->screen_h = DEF_SC_H;
	}
	return (opt);
}
