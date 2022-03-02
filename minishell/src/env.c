/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:51:50 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	na_show_env(t_par *par)
{
	int	i;
	int	a;
	int	flag;

	i = 0;
	while (par->env[i])
	{
		a = 0;
		flag = 0;
		while (par->env[i][a] != '\0')
		{
			if (par->env[i][a] == '=')
				flag = 1;
			a++;
		}
		if (flag == 1)
		{
			ft_putstr_fd(par->env[i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
	par->code_of_error_2 = 0;
}

void	find_name_of_var(char *str, int *flag, int *i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '=')
		{
			*flag = 1;
			break ;
		}
		*i = *i + 1;
	}
}
