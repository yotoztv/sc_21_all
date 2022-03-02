/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:07 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/23 05:08:54 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(int size, char c)
{
	int		i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int		edit_print(char *str, t_check check)
{
	int count;

	count = 0;
	if (check.minus == 0)
	{
		print_width((check.width - ft_strlen(str)),
			((check.zero == 1) ? '0' : ' '));
		ft_putstr_fd(str, 1);
		count = (check.width > ft_strlen(str) ? check.width : ft_strlen(str));
	}
	else if (check.minus == 1)
	{
		ft_putstr_fd(str, 1);
		print_width((check.width - ft_strlen(str)),
			((check.zero == 1) ? '0' : ' '));
		count = (check.width > ft_strlen(str) ? check.width : ft_strlen(str));
	}
	return (count);
}

int		convers_spec(char spec, va_list argv, t_check check)
{
	int		count;

	ft_convertion(&check);
	count = 0;
	if (spec == 'd' || spec == 'i')
		count += conv_digital(check, argv);
	else if (spec == 's')
		count += conv_str(check, argv);
	else if (spec == 'c')
		count += conv_char(check, argv);
	else if (spec == 'x')
		count += conv_hex(check, argv);
	else if (spec == 'X')
		count += conv_hex_xm(check, argv);
	else if (spec == 'p')
		count += conv_point(check, argv);
	else if (spec == 'u')
		count += conv_unsign(check, argv);
	else if (spec == '%')
		count += conv_procent(check);
	else
		return (0);
	return (count);
}

int		ft_printf(const char *str, ...)
{
	va_list	argv;
	t_check	check;

	if (str == NULL)
		return (-1);
	va_start(argv, str);
	check.count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check = init_check(check);
			check = parser_flag(check, (char *)str, argv);
			while (!is_spec(*str))
				str++;
			check.count += convers_spec(*str, argv, check);
		}
		else
			check.count += write(1, str, 1);
		str++;
	}
	va_end(argv);
	return (check.count);
}
