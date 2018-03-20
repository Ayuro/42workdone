/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:20:06 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:20:07 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlink(char *s1, char *s2, char c)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 || !s2 || !(str = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	j = 0;
	str = ft_strcpy(str, s1);
	while (s1[i])
		i++;
	str[i] = c;
	i++;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
