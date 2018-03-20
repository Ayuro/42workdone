/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:07:27 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/02 16:43:11 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	char	*str;

	b = 0;
	e = 0;
	if (!s)
	{
		return (NULL);
	}
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && (s[b]))
	{
		b++;
	}
	e = ft_strlen(s) - 1;
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && (b <= e))
	{
		e--;
	}
	str = ft_strsub(s, b, e - b + 1);
	return (str);
}
