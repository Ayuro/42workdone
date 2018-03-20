/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:06:52 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:06:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_s(void *s)
{
	char	*str;
	int		len;

	str = (char *)s;
	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	ft_putstr(str);
	return (len);
}
