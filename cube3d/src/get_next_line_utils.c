/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:00:40 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:00:47 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

size_t			ft_strlen_ch(const char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != 0)
		i++;
	return (i);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*pd;
	char		*ps;

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

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (len == 0)
		return (dst);
	if (dst >= src)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}

char			*ft_strjoin_fr(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen_ch((char *)s1);
	s2_len = ft_strlen_ch((char *)s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_memmove(str, s1, s1_len);
	ft_memmove(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free((char *)s1);
	return (str);
}
