/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:07:19 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		basic_count(char **str, int l)
{
	if (!str)
		return (0);
	while (str[l])
		l++;
	return (l);
}

char	*define_str(t_par *par, int j, int *i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	if (check_valid(par, &j, i) == 1)
	{
		str = ft_strjoin_and_free(str, "error: not a valid identifier");
		return (str);
	}
	while (par->time_str[j][*i] != '\0' && par->time_str[j][*i] != '=')
	{
		if (check_symbol(par->time_str[j][*i]) == 0
		|| (*i == 0 && par->time_str[j][*i] >= '0'
		&& par->time_str[j][*i] <= '9'))
		{
			free(str);
			str = (char *)malloc(sizeof(char) * 1);
			str[0] = '\0';
			str = ft_strjoin_and_free(str, "error: not a valid identifier");
			return (str);
		}
		str = ft_strjoin_mod_free(str, par->time_str[j][*i]);
		*i = *i + 1;
	}
	return (str);
}

void	change_value(t_par *par, int j, int p, int i)
{
	char	*str;

	while (par->time_str[j])
	{
		i = 0;
		str = define_str(par, j, &i);
		p = j + 1;
		while (par->time_str[p])
		{
			i = 0;
			while (par->time_str[p][i] != '\0' && par->time_str[p][i] != '=')
				i++;
			if (find_str(par->time_str[p], str) != -1
			&& par->time_str[p][i] == '=')
				new_line_exp(par, j, par->time_str[p]);
			p++;
		}
		j++;
		free(str);
	}
}

void	no_var_in_env(int flag, char **environ, int *n, char *str)
{
	if (flag != -7)
	{
		environ[*n] = ft_strjoin_and_free(environ[*n], str);
		*n = *n + 1;
	}
}

void	change_var(char **environ, int *n, int *flag, char *str)
{
	environ[*n] = ft_strjoin_and_free(environ[*n], str);
	*flag = -7;
	*n = *n + 1;
}
