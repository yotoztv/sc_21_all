/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 11:05:00 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/20 11:05:03 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	ia;
	size_t	iz;

	if (s1 == 0 || set == 0)
		return (NULL);
	ia = 0;
	while (s1[ia] != 0 && ft_strchr(set, s1[ia]) != 0)
		ia++;
	iz = ft_strlen(s1 + ia);
	if (iz != 0)
		while (s1[iz + ia - 1] != 0 && ft_strchr(set, s1[iz + ia - 1]) != 0)
			iz--;
	if (!(str = ft_calloc(sizeof(char), iz + 1)))
		return (NULL);
	ft_strlcpy(str, s1 + ia, iz + 1);
	return (str);
}
