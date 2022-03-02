/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:10:29 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/28 02:10:36 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int		ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}

t_check	init_check(t_check check)
{
	check.zero = 0;
	check.minus = 0;
	check.width = 0;
	check.point = 0;
	check.precision = 0;
	check.dopminus = 1;
	return (check);
}

int		is_spec(char c)
{
	return (c == 'd' || c == 'i' || c == 's' || c == 'c' ||
		c == 'x' || c == 'X' || c == 'p' || c == 'u' || c == '%');
}

t_check	parser_flag(t_check check, char *str, va_list argv)
{
	int		i;

	i = 0;
	while (str[i] && !(is_spec(str[i])))
	{
		if (str[i] == '-')
			check.minus = 1;
		else if (str[i] == '0' && check.width == 0 && check.point == 0)
			check.zero = 1;
		else if (ft_isdigit(str[i]) && check.point == 0)
			check.width = (check.width * 10) + (str[i] - '0');
		else if (str[i] == '.')
			check.point = 1;
		else if (ft_isdigit(str[i]) && check.point == 1)
			check.precision = (check.precision * 10) + (str[i] - '0');
		else if (str[i] == '*' && check.point == 0)
			check.width = va_arg(argv, int);
		else if (str[i] == '*' && check.point == 1)
			check.precision = va_arg(argv, int);
		i++;
	}
	return (check);
}
