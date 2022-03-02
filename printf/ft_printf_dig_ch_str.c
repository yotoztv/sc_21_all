/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dig_ch_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:27:55 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/28 02:27:59 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_of_digital(int num, t_check *check)
{
	if (num < 0)
	{
		num = -1 * num;
		check->dopminus *= -1;
	}
	if (check->dopminus == -1 && check->point == 0 && check->precision == 0 &&
		check->zero == 1 && check->minus == 0)
	{
		check->point = 1;
		check->precision = check->width - 1;
		check->width = 0;
	}
	return (num);
}

int			conv_digital(t_check check, va_list argv)
{
	int		num;
	int		count;
	char	*str;
	char	*str0;

	num = va_arg(argv, int);
	num = flag_of_digital(num, &check);
	if (num == 0 && check.precision == 0 && check.point == 1)
		str = ft_strdup("");
	else
		str = ft_itoa(num);
	if (check.precision > ft_strlen(str))
	{
		str0 = ft_strnew(check.precision - ft_strlen(str));
		str0 = ft_memset(str0, '0', check.precision - ft_strlen(str));
		str = ft_strjoin(str0, str);
		free(str0);
	}
	if ((check.precision != 0 || check.point == 1) && check.zero == 1)
		check.zero = 0;
	if (check.dopminus == -1)
		str = ft_strjoin("-", str);
	count = edit_print_di(str, check);
	free(str);
	return (count);
}

int			conv_str(t_check check, va_list argv)
{
	int		count;
	char	*str;
	char	*start;

	start = va_arg(argv, char *);
	if (!start)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(start);
	if ((check.point == 1) && (check.precision < ft_strlen(str)))
		str[check.precision] = '\0';
	count = edit_print_str(str, check);
	free(str);
	return (count);
}

int			conv_char(t_check check, va_list argv)
{
	int		chint;
	int		count;

	chint = va_arg(argv, int);
	count = edit_print_char(chint, check);
	return (count);
}
