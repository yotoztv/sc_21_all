/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 05:07:41 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/21 05:07:48 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_m(int n)
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

char	*ft_itoa_p(int n)
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

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		str = ft_itoa_m(n);
	if (n >= 0)
		str = ft_itoa_p(n);
	return (str);
}
