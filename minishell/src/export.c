/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:42:54 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_value_ex(int *k, char *str, t_par *par, char **str2)
{
	int	p;

	p = find_str(par->env[*k], str) + 1;
	while (par->env[*k][p] != '\0')
	{
		*str2 = ft_strjoin_mod_free(*str2, par->env[*k][p]);
		p++;
	}
}

char	*ft_code(t_par *par, char *str2, int *i)
{
	char *tmp;

	par->code_of_error = par->code_of_error_2;
	tmp = ft_itoa(par->code_of_error);
	str2 = ft_strjoin_and_free(str2, tmp);
	*i = *i + 1;
	free(tmp);
	return (str2);
}

void	open_dollar_ex(int *i, t_par *par, int *j, char **str2)
{
	int		k;
	char	*str;

	str = start_value_ex(&k, i, par, j);
	if (par->time_str[*j][*i] == '?')
		*str2 = ft_code(par, *str2, i);
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
				write_value_ex(&k, str, par, str2);
			k++;
		}
		free(str);
	}
}

void	new_line_exp(t_par *par, int j, char *str2)
{
	free(par->time_str[j]);
	par->time_str[j] = malloc(sizeof(char) * 1);
	par->time_str[j][0] = '\0';
	par->time_str[j] = ft_strjoin_and_free(par->time_str[j], str2);
}

void	value_of_var(t_par *par)
{
	int		j;
	int		i;
	char	*str2;

	j = 0;
	while (par->time_str[j])
	{
		str2 = malloc(sizeof(char) * 1);
		str2[0] = '\0';
		i = 0;
		while (par->time_str[j][i] != '\0')
		{
			if (par->time_str[j][i] == '(')
				open_dollar_ex(&i, par, &j, &str2);
			else
			{
				str2 = ft_strjoin_mod_free(str2, par->time_str[j][i]);
				i = i + 1;
			}
		}
		new_line_exp(par, j, str2);
		free(str2);
		j++;
	}
	par->time_str[j] = NULL;
}
