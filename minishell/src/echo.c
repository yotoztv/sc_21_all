/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:54:05 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_main(t_par *par, int *j, int *i)
{
	while (par->time_str[*j][*i] != '\0')
	{
		if (par->time_str[*j][*i] == '(')
			open_dollar(i, par, j);
		else
		{
			write(1, &par->time_str[*j][*i], 1);
			*i = *i + 1;
		}
	}
}

void	basic_count_echo(char **str, int *l)
{
	while (str[*l])
		*l = *l + 1;
}

void	na_echo(t_par *par)
{
	int	j;
	int	i;
	int	num;
	int	flag;

	num = 0;
	basic_count_echo(par->time_str, &num);
	j = 1;
	flag = 0;
	i = 0;
	check_option_start(par, &j, &i, &flag);
	while (par->time_str[j])
	{
		echo_main(par, &j, &i);
		write_space(j, num);
		j++;
		i = 0;
	}
	if (flag != 1)
		write(1, "\n", 1);
	par->code_of_error_2 = 0;
}
