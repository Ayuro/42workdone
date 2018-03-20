/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_of_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:56:12 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:56:12 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static long		mod_atoi(char *s)
{
	int		i;
	long	nbr;
	t_iny	sign;

	if (s[0] == '\0')
		return (0);
	i = 0;
	sign = (s[i] == '-' ? -1 : 1);
	i += (s[i] == '-' || s[i] == '+' ? 1 : 0);
	nbr = 0;
	while ((s[i] >= '0' && s[i] <= '9') && \
			s[i] != '\0' && ft_strchr(SPACES, s[i]) == NULL)
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	return (nbr * sign);
}

static int		parse_line_nbr(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		while (ft_strchr(SPACES, s[i]) != NULL && s[i] != '\0')
			i++;
		if (ft_strchr(SPACES, s[i]) == NULL && s[i] != '\0')
			ret += 1;
		while (ft_strchr(SPACES, s[i]) == NULL && s[i] != '\0')
			i++;
	}
	return (ret);
}

static void		parse_line_add_value(char *s, int pos)
{
	long	value;

	value = mod_atoi((char *)s + pos);
	if (sg_map()->cp != NULL &&
		sg_map()->cp->ox / DEF_PADDING != sg_map()->dim_w - 1)
		map_add_point(value);
	else
		map_add_line(value);
}

void			parse_line_of_map(const char *s)
{
	int		size;
	int		pos;

	size = parse_line_nbr((char*)s);
	if (sg_map()->dim_w == 0)
		sg_map()->dim_w = size;
	else if (size == 0)
		return ;
	else if (sg_map()->dim_w != size)
		exit_failure_1s(ERR_MAPDIMS, TRUE);
	pos = 0;
	while (s[pos] != '\0')
	{
		while (ft_strchr(SPACES, s[pos]) != NULL && s[pos] != '\0')
			pos++;
		if (s[pos] == '\0')
			break ;
		parse_line_add_value((char *)s, pos);
		while (ft_strchr(SPACES, s[pos]) == NULL && s[pos] != '\0')
			pos++;
	}
	if (sg_map()->cp->oy == 0)
		sg_map()->ptr = sg_map()->cp;
}
