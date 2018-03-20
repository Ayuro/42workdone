/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backslash_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:17:10 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:17:11 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_backslash_check(char const *s, int i)
{
	int		n;

	n = 0;
	if (!s || i < 0 || i > (int)ft_strlen(s))
		return (false);
	if (i - 1 >= 0 && s[i - 1] == '\\')
	{
		n++;
		i--;
		while (i - 1 >= 0 && s[i - 1] == '\\')
		{
			i--;
			n++;
		}
		if (n % 2 == 1)
			return (true);
	}
	return (false);
}
