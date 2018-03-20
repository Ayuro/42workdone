/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:41:43 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:41:46 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	char	*str;

	b = 0;
	e = 0;
	if (!s)
		return (NULL);
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && (s[b]))
		b++;
	e = ft_strlen(s) - 1;
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && (b <= e))
		e--;
	str = ft_strsub(s, b, e - b + 1);
	return (str);
}
