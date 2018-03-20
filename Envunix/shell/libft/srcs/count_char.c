/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:16:45 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:16:46 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == c)
			count++;
	return (count);
}
