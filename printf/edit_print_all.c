/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_print_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:20:22 by dlucio            #+#    #+#             */
/*   Updated: 2020/07/30 22:20:24 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		edit_print_p(char *str, t_check check)
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

int		edit_print_str(char *str, t_check check)
{
	int count;

	if (check.width < 0)
	{
		check.width *= -1;
		check.minus = 1;
	}
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

int		edit_print_char(int chint, t_check check)
{
	int count;

	if (check.width < 0)
	{
		check.width *= -1;
		check.minus = 1;
	}
	count = 0;
	if (check.minus == 0)
	{
		print_width((check.width - 1),
			((check.zero == 1) ? '0' : ' '));
		write(1, &chint, 1);
		count = (check.width > 1 ? check.width : 1);
	}
	else if (check.minus == 1)
	{
		write(1, &chint, 1);
		print_width((check.width - 1),
			((check.zero == 1) ? '0' : ' '));
		count = (check.width > 1 ? check.width : 1);
	}
	return (count);
}

int		edit_print_di(char *str, t_check check)
{
	int count;

	if (check.width < 0)
	{
		check.width *= -1;
		check.minus = 1;
	}
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
