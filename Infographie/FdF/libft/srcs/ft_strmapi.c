/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:35:35 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:35:37 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	int		i;
	char	*snew;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	if ((snew = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = (f)(i, s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
