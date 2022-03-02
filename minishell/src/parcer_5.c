/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 12:25:54 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	end_of_double_quotes(char *line, int *i, int *j, t_par *par)
{
	if (line[*i] == 34 && line[*i + 1] == ' ')
	{
		*i = *i + 1;
		while (line[*i] == ' ' && line[*i] != '\0')
			*i = *i + 1;
		if (line[*i] != '\0')
			new_line(par, j);
	}
	else
		*i = *i + 1;
}

void	some_fun(t_par *par, int *j, int *i, char *line)
{
	par->str_na[*j] = ft_strjoin_and_free(par->str_na[*j], "&z28!-");
	par->str_na[*j] = ft_strjoin_mod_free(par->str_na[*j], line[*i]);
}

void	no_in_quotes(int *j, int *i, char *line, t_par *par)
{
	while (check_end_word(line[*i]) == 1)
	{
		if (par->flag == 5)
			new_line(par, j);
		par->flag = 0;
		if (line[*i] == 92 && line[*i + 1] != '\0')
			print_symbol(par, line[*i + 1], *j, i);
		else if (check_command(line[*i]) == 1)
		{
			if (*i != 0)
				if (line[*i - 1] != ' ')
					new_line(par, j);
			some_fun(par, j, i, line);
			if (line[*i] == '>' && line[*i + 1] == '>')
				print_symbol(par, line[*i + 1], *j, i);
			par->flag = 5;
		}
		else if (check_dollar(line[*i], line[*i + 1]) == 1)
			write_special_dollar(par, line[*i], *j);
		else
			par->str_na[*j] = ft_strjoin_mod_free(par->str_na[*j], line[*i]);
		*i = *i + 1;
	}
	if (line[*i] == ' ')
		skip_space(line, i, par, j);
}

void	in_double_quotes(int *i, char *l, t_par *par, int *j)
{
	while (l[*i] != 34 && l[*i] != '\0')
	{
		par->flag = 0;
		if (l[*i] == 92)
		{
			if (l[*i + 1] == 34 || l[*i + 1] == '$')
				par->flag = 2;
			if (l[*i] == 92 && l[*i + 1] == 92)
			{
				print_symbol(par, 92, *j, i);
				par->flag = 3;
			}
		}
		if (par->flag == 0)
		{
			if (check_dollar(l[*i], l[*i + 1]) == 1)
				write_special_dollar(par, l[*i], *j);
			else
				par->str_na[*j] = ft_strjoin_mod_free(par->str_na[*j], l[*i]);
		}
		if (par->flag == 2)
			print_symbol(par, l[*i + 1], *j, i);
		*i = *i + 1;
	}
	end_of_double_quotes(l, i, j, par);
}

int		size_of_mas_par_str(char *line)
{
	int	i;
	int	flag;
	int	count;
	int	no_arg;

	no_arg = 0;
	i = 0;
	count = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		no_arg = 1;
		if (line[i] != 39 && line[i] != 34)
			no_in_quotes_count(&count, &i, &flag, line);
		if (line[i] == 34 || line[i] == 39)
			in_quotes_count(&count, &i, &flag, line);
	}
	return (count + no_arg);
}
