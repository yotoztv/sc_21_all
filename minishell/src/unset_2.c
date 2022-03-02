/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 17:18:44 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		count_unset(t_par *par)
{
	int		o;
	int		k;
	int		flag;

	k = 0;
	flag = 0;
	k = count_del_lines(par, flag, k);
	o = 0;
	while (par->env[o])
		o++;
	return (o - k);
}

int		count_del_lines(t_par *par, int flag, int k)
{
	int		j;
	int		o;

	o = 0;
	while (par->env[o])
	{
		flag = 0;
		j = 1;
		while (par->time_str[j])
		{
			if (find_str(par->env[o], par->time_str[j]) != -1 &&
			par->time_str[j][0] != '\0')
				flag = 1;
			j++;
		}
		if (flag == 1)
			k++;
		o++;
	}
	return (k);
}

int		parcer_unset(t_par *par, int j, int *p)
{
	int	i;

	i = 0;
	while (par->time_str[j][i] != '\0')
	{
		if (par->time_str[j][i] >= '0' && par->time_str[j][i] <= '9'
		&& i == 0)
		{
			*p = 1;
			par->code_of_error_2 = 1;
			return (1);
		}
		if (check_symbol(par->time_str[j][i]) != 1)
		{
			*p = 1;
			par->code_of_error_2 = 1;
			return (1);
		}
		i++;
	}
	par->code_of_error_2 = 0;
	return (0);
}

char	*new_line_of_environ_un(char *str)
{
	char *environ;

	environ = (char *)malloc(sizeof(char) * 1);
	environ[0] = '\0';
	environ = ft_strjoin(environ, str);
	return (environ);
}
