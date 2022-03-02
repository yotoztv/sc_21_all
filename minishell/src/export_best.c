/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:34:59 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:33:30 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**export_out(t_par *par, int w, int flag)
{
	int		i;
	int		o;

	if (ft_if_sort(par->env, 0, w - 1) == 0)
		par->env = sorting(par->env, 0, w - 1);
	o = 0;
	while (par->env[o])
	{
		i = 0;
		left_base(&flag);
		while (par->env[o][i] != '\0')
		{
			write(1, &par->env[o][i], 1);
			if (par->env[o][i++] == '=' && flag != 1)
			{
				ft_putchar_fd(34, 1);
				flag = 1;
			}
		}
		if (flag == 1)
			ft_putchar_fd(34, 1);
		write(1, "\n", 1);
		o++;
	}
	return (par->env);
}

void	export_gen(char *arg, t_par *par)
{
	int		j;
	int		flag;
	char	*name_var;
	char	*name_var_env;

	j = -1;
	flag = 0;
	name_var = ft_find_name(arg);
	while (par->env[++j])
	{
		name_var_env = ft_find_name(par->env[j]);
		if (ft_strncmp(name_var, name_var_env,
		ft_strlen(name_var_env) + 1) == 0)
		{
			flag = 1;
			free(name_var_env);
			break ;
		}
		free(name_var_env);
	}
	if (flag == 0)
		par->env = add_line(par, arg);
	else
		change_line(par, arg, j);
	free(name_var);
}

void	change_line(t_par *par, char *str, int j)
{
	if (ft_strchr(str, '='))
	{
		free(par->env[j]);
		par->env[j] = ft_calloc(sizeof(char), 1);
		par->env[j] = ft_strjoin_and_free(par->env[j], str);
	}
}

char	**add_line(t_par *par, char *str)
{
	char	**new_env;
	int		j;

	j = 0;
	new_env = (char **)ft_calloc(sizeof(char*), basic_count(par->env, 0) + 2);
	while (par->env[j])
	{
		new_env[j] = ft_strdup(par->env[j]);
		j++;
	}
	new_env[j] = ft_strdup(str);
	free_mas(par->env);
	return (new_env);
}

char	**my_export(t_par *par)
{
	int		j;
	int		w;
	int		flag;

	flag = 0;
	w = basic_count(par->env, 0);
	if (par->time_str[1] == NULL)
		par->code_of_error_2 = 0;
	if (par->time_str[1] == NULL)
		return (export_out(par, w, flag));
	else
	{
		j = 0;
		while (par->time_str[++j])
		{
			if (parcer_of_export(par, j) == 1)
			{
				export_gen(par->time_str[j], par);
				par->code_of_error_2 = 0;
			}
			else
				write_error_inf(par->time_str[j], par);
		}
	}
	return (par->env);
}
