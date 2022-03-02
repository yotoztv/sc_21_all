/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 08:09:32 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/14 08:09:37 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ps = ((char *)s + i);
		i++;
	}
	if (ps)
		return (ps);
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
