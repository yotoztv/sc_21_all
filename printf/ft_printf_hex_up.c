/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:15:25 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/28 02:15:31 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					back_char(int hex, int x)
{
	if ((hex >= 0) && (hex <= 9))
		return (hex + 48);
	else if (hex == 10)
		return ('a' - x);
	else if (hex == 11)
		return ('b' - x);
	else if (hex == 12)
		return ('c' - x);
	else if (hex == 13)
		return ('d' - x);
	else if (hex == 14)
		return ('e' - x);
	else if (hex == 15)
		return ('f' - x);
	else
		return ('X');
}

char					*ft_itoa_hex(unsigned int n, int x)
{
	int					i;
	unsigned int		m;
	unsigned int		p;
	char				*str;

	i = 0;
	m = n;
	p = 0;
	while (m /= 16)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	m = n;
	while (i >= 0)
	{
		p = m / 16;
		str[i] = back_char(m - (p * 16), x);
		m = m / 16;
		i--;
	}
	return (str);
}

int						conv_hex(t_check check, va_list argv)
{
	unsigned int		numx;
	int					count;
	char				*str;
	char				*str0;

	numx = va_arg(argv, unsigned int);
	if (numx == 0 && check.precision == 0 && check.point == 1)
		str = ft_strdup("");
	else
		str = ft_itoa_hex(numx, 0);
	if ((check.precision != 0 || check.point == 1) && check.zero == 1)
		check.zero = 0;
	if (check.precision > ft_strlen(str))
	{
		str0 = ft_strnew(check.precision - ft_strlen(str));
		str0 = ft_memset(str0, '0', check.precision - ft_strlen(str));
		str = ft_strjoin(str0, str);
		free(str0);
	}
	count = edit_print_di(str, check);
	free(str);
	return (count);
}

int						conv_hex_xm(t_check check, va_list argv)
{
	unsigned int		numx;
	int					count;
	char				*str;
	char				*str0;

	numx = va_arg(argv, int);
	if (numx == 0 && check.precision == 0 && check.point == 1)
		str = ft_strdup("");
	else
		str = ft_itoa_hex(numx, 32);
	if ((check.precision != 0 || check.point == 1) && check.zero == 1)
		check.zero = 0;
	if (check.precision > ft_strlen(str))
	{
		str0 = ft_strnew(check.precision - ft_strlen(str));
		str0 = ft_memset(str0, '0', check.precision - ft_strlen(str));
		str = ft_strjoin(str0, str);
		free(str0);
	}
	count = edit_print_di(str, check);
	free(str);
	return (count);
}
