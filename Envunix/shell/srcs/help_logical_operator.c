/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_logical_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:06:51 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:06:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

int		count_op(char *s)
{
	int		count;
	char	*tmp;
	char	c;

	if (!s)
		return (0);
	tmp = s;
	count = 0;
	c = next_operator(tmp);
	while (c != '\0')
	{
		tmp = no_double_char(tmp, c);
		c = next_operator(tmp);
		count++;
	}
	return (count);
}
