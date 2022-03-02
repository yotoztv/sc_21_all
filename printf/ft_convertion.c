/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:01:19 by dlucio            #+#    #+#             */
/*   Updated: 2020/08/01 16:01:25 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertion(t_check *check)
{
	if (check->precision < 0)
	{
		check->precision = 0;
		check->point = 0;
	}
	if (check->width < 0)
	{
		check->minus = 1;
		check->width *= -1;
	}
	if (check->minus == 1)
	{
		check->zero = 0;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	while (ps[i] != (char)c)
	{
		if (ps[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&ps[i]);
}
