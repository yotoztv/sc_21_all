/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:04:02 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/28 02:04:08 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str)
		while (str[i] != 0)
			i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	if (!(copy = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_itoa_m(int n)
{
	int		i;
	int		m;
	char	*str;

	i = 0;
	m = -n;
	while (m /= 10)
		i++;
	i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	m = -n;
	while (i > -1)
	{
		str[i] = m % 10 + 48;
		m = m / 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

char		*ft_itoa_p(int n)
{
	int		i;
	int		m;
	char	*str;

	i = 0;
	m = n;
	while (m /= 10)
		i++;
	if (n < 0)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	m = n;
	while (i > -1)
	{
		str[i] = m % 10 + 48;
		m = m / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	if (n < 0)
		str = ft_itoa_m(n);
	if (n >= 0)
		str = ft_itoa_p(n);
	return (str);
}
