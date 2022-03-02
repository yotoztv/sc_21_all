/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:42:02 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/11 00:42:10 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t count)
{
	size_t			i;
	unsigned char	*p2;
	unsigned char	*p1;

	p2 = (unsigned char *)s2;
	p1 = (unsigned char *)s1;
	i = 0;
	while (i != count)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		else
			i++;
	}
	return (0);
}
