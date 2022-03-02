/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_u_pr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:20:19 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/28 02:20:23 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_itoa_point(size_t n, int x)
{
	int					i;
	size_t				m;
	size_t				p;
	char				*str;

	i = 2;
	m = n;
	p = 0;
	while (m /= 16)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	m = n;
	while (i >= 2)
	{
		p = m / 16;
		str[i] = back_char(m - (p * 16), x);
		m = m / 16;
		i--;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

int						conv_point(t_check check, va_list argv)
{
	size_t				numx;
	int					count;
	char				*str;

	numx = va_arg(argv, size_t);
	str = ft_itoa_point(numx, 0);
	if (!str)
		return (0);
	count = edit_print_p(str, check);
	free(str);
	return (count);
}

char					*ft_itoa_unsign(unsigned int n)
{
	int					i;
	unsigned int		m;
	char				*str;

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

int						conv_unsign(t_check check, va_list argv)
{
	unsigned int		numx;
	int					count;
	char				*str;
	char				*str0;

	numx = va_arg(argv, unsigned int);
	if (numx == 0 && check.precision == 0 && check.point == 1)
		str = ft_strdup("");
	else
		str = ft_itoa_unsign(numx);
	if ((check.precision != 0 || check.point == 1) && check.zero == 1)
		check.zero = 0;
	if (check.precision > ft_strlen(str))
	{
		str0 = ft_strnew(check.precision - ft_strlen(str) - 1);
		str0 = ft_memset(str0, '0', check.precision - ft_strlen(str));
		str = ft_strjoin(str0, str);
		free(str0);
	}
	count = edit_print_di(str, check);
	free(str);
	return (count);
}

int						conv_procent(t_check check)
{
	int					count;
	char				*str[2];

	str[0] = (char *)'%';
	str[1] = (char *)'\0';
	count = edit_print((char *)str, check);
	return (count);
}
