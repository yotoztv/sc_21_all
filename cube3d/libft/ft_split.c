/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 21:49:10 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/20 21:49:13 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		qt_jcalc(char const *s, char c)
{
	unsigned int	i;
	unsigned int	sumj;

	if (!s[0])
		return (0);
	i = 0;
	sumj = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			sumj++;
			while (s[i] && s[i] == c)
				i++;
			continue;
		}
		i++;
	}
	if (s[i - 1] != c)
		sumj++;
	return (sumj);
}

void				qt_nej(char **nej, unsigned int *lenx, char c)
{
	unsigned int	i;

	*nej = *nej + *lenx;
	*lenx = 0;
	i = 0;
	while (**nej == c)
		(*nej)++;
	while ((*nej)[i])
	{
		if ((*nej)[i] == c)
			return ;
		(*lenx)++;
		i++;
	}
}

char				**ft_malloc_error(char **mtrx)
{
	unsigned int	i;

	i = 0;
	while (mtrx[i])
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char			**mtrx;
	char			*nej;
	unsigned int	lenx;
	unsigned int	lenj;
	unsigned int	i;

	if (!s)
		return (NULL);
	lenj = qt_jcalc(s, c);
	if (!(mtrx = (char **)malloc(sizeof(char *) * (lenj + 1))))
		return (NULL);
	i = 0;
	nej = (char *)s;
	lenx = 0;
	while (i < lenj)
	{
		qt_nej(&nej, &lenx, c);
		if (!(mtrx[i] = (char *)malloc(sizeof(char) * (lenx + 1))))
			return (ft_malloc_error(mtrx));
		ft_strlcpy(mtrx[i], nej, lenx + 1);
		i++;
	}
	mtrx[i] = NULL;
	return (mtrx);
}
