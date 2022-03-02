/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 00:53:02 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/15 00:53:05 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;

	if (*needle == '\0')
		return ((char *)haystack);
	len_n = ft_strlen(needle);
	while (*haystack != '\0' && len >= len_n)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_n) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
