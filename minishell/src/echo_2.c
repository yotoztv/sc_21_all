/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 00:29:15 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int		find_str(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '=' && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str2[i] != str1[i])
			return (-1);
		i++;
	}
	if ((size_t)i != ft_strlen(str2))
		return (-1);
	return (i);
}

int		check_s(char s)
{
	if (s == '-' || s == 'n')
		return (1);
	return (0);
}

void	no_option(t_par *par, int *i, int minus, int *j)
{
	while (check_s(par->time_str[*j][minus]) == 1)
	{
		write(1, &par->time_str[*j][minus], 1);
		minus++;
	}
	*i = minus;
}

int		check_option(t_par *par, int *j, int *flag, int *i)
{
	int	minus;
	int	in;

	in = 0;
	if (par->time_str[*j][in] == '-')
	{
		minus = in;
		in++;
		if (par->time_str[*j][in] == 'n')
		{
			while (par->time_str[*j][in] == 'n')
				in++;
			if (par->time_str[*j][in] == '\0')
			{
				*flag = 1;
				return (1);
			}
		}
		if (*flag == 0)
			no_option(par, i, minus, j);
	}
	return (0);
}

int		check_symbol_echo(char c)
{
	if ((c >= 'A' && c <= 'Z') ||
	(c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c == '_'))
		return (1);
	return (0);
}
