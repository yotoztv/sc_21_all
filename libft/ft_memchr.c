/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:45:51 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/11 00:45:55 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	while (i != n)
	{
		if (ps[i] == (char)c)
			return (ps + i);
		i++;
	}
	return (NULL);
}
