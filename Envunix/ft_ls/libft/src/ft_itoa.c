/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:47:50 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:47:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_get(char *nbr, unsigned int val, int len, int i)
{
	unsigned int		mod;
	int					power;
	int					flag;
	int					count;

	while (i < len)
	{
		power = 1;
		flag = 0;
		count = -1;
		mod = val;
		while (val > 9)
		{
			val /= 10;
			flag++;
		}
		nbr[i] = (val + '0');
		i++;
		while ((count += 1) < flag)
			power *= 10;
		val = mod % power;
	}
	nbr[i] = '\0';
	return (nbr);
}

static int	ft_itoa_len(int n)
{
	int				len;
	unsigned int	val;

	len = 0;
	if (n < 0)
		len++;
	val = (n < 0) ? -n : n;
	while (val > 0)
	{
		val /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	val;
	int				i;
	char			*nbr;

	val = (n < 0) ? -n : n;
	len = (n == 0) ? 1 : ft_itoa_len(n);
	if ((nbr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = (n <= -1) ? 1 : 0;
	if (i == 1)
		nbr[0] = '-';
	nbr = ft_itoa_get(nbr, val, len, i);
	return (nbr);
}
