/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:40:54 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:40:55 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_cnt(char *s, char c)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			sum++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (sum);
}

static char		*ft_strsplit_alloc_s(int slot, char *s, char c)
{
	int		i_start;
	int		i_end;
	int		i_slot;
	char	*n_s;

	i_start = 0;
	while (s[i_start] == c)
		i_start++;
	i_slot = 0;
	while (i_slot < slot)
	{
		while (s[i_start] != '\0' && s[i_start] != c)
			i_start++;
		while (s[i_start] != '\0' && s[i_start] == c)
			i_start++;
		i_slot++;
	}
	i_end = i_start;
	while (s[i_end] != '\0' && s[i_end] != c)
		i_end++;
	if ((n_s = ft_strsub(s, i_start, i_end - i_start)) == NULL)
		return (NULL);
	return (n_s);
}

char			**ft_strsplit(const char *s, char c)
{
	int		len;
	char	**tab;
	int		slot;

	if (s == NULL)
		return (NULL);
	len = ft_strsplit_cnt((char *)s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	slot = 0;
	while (slot < len)
	{
		tab[slot] = ft_strsplit_alloc_s(slot, (char *)s, c);
		slot++;
	}
	tab[slot] = NULL;
	return (tab);
}
