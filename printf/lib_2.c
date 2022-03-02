/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:20:39 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/31 13:28:34 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*pb;

	i = 0;
	pb = (char*)b;
	while (i != len)
	{
		pb[i] = c;
		i++;
	}
	return (b);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
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

void		*ft_memmove(void *dst, const void *src, size_t len)
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

char		*ft_strjoin(char const *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_memmove(str, s1, s1_len);
	ft_memmove(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s2);
	return (str);
}
