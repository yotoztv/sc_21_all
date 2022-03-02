/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 02:17:14 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/09 02:17:19 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pd;
	char	*ps;

	if (!dst && !src)
		return (NULL);
	ps = (char *)src;
	pd = (char *)dst;
	i = 0;
	while (i != n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (pd);
}
