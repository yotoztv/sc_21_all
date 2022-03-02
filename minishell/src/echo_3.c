/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 17:02:49 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_option_start(t_par *par, int *j, int *i, int *flag)
{
	while (par->time_str[*j])
	{
		if (check_option(par, j, flag, i) != 1)
			break ;
		*j = *j + 1;
	}
}

void	write_value(int *k, char *str, t_par *par)
{
	int	p;

	p = find_str(par->env[*k], str) + 1;
	while (par->env[*k][p] != '\0')
	{
		write(1, &par->env[*k][p], 1);
		p = p + 1;
	}
}

char	*start_value(int *k, int *i, t_par *par, int *j)
{
	char *str;

	*k = 0;
	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	*i = *i + 1;
	*i = (par->time_str[*j][*i] == '$' && par->time_str[*j][*i + 1] == ')')
	? *i + 2 : *i;
	return (str);
}

void	open_dollar(int *i, t_par *par, int *j)
{
	int		k;
	char	*str;

	str = start_value(&k, i, par, j);
	if (par->time_str[*j][*i] == '?')
	{
		ft_putnbr_fd(errno, 1);
		*i = *i + 1;
	}
	else
	{
		while (check_symbol_echo(par->time_str[*j][*i]) == 1)
		{
			str = ft_strjoin_mod_free(str, par->time_str[*j][*i]);
			*i = *i + 1;
		}
		while (par->env[k])
		{
			if (find_str(par->env[k], str) != -1)
				write_value(&k, str, par);
			k++;
		}
	}
	free(str);
}

void	write_space(int j, int num)
{
	if (j < (num - 1))
		write(1, " ", 1);
}
