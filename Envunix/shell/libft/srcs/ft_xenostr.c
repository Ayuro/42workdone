/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:07:45 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 14:07:46 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		xeno_count(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_xenostr(char *s, char c)
{
	int		i;
	int		j;
	char	*xeno;

	i = xeno_count(s, c);
	if (!s || !(xeno = (char*)malloc(sizeof(char) * ft_strlen(s) - i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			xeno[j] = s[i];
			j++;
		}
		i++;
	}
	xeno[j] = '\0';
	return (xeno);
}
