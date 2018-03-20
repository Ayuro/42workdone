/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:35:22 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:35:23 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*snew;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if ((snew = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = (f)(s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
