/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 06:19:35 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/10 06:19:39 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pd;
	unsigned char	*ps;

	ps = (unsigned char *)src;
	pd = (unsigned char *)dst;
	i = 0;
	while (i != n)
	{
		pd[i] = ps[i];
		if (ps[i] == (unsigned char)c)
			return (pd + i + 1);
		i++;
	}
	return (NULL);
}
