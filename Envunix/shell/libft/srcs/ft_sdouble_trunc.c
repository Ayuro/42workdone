/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdouble_trunc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:19:21 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:19:23 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sdouble_trunc(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		i++;
		if (s[i] == c && s[i + 1] && s[i + 1] == c)
			break ;
	}
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
		if (s[i] == c && s[i + 1] && s[i + 1] == c)
			break ;
	}
	str[i] = '\0';
	return (str);
}
