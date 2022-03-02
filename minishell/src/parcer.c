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

void	check_symb(int *i, t_par *par)
{
	*i = *i + 1;
	par->flag = 0;
}

void	in_quotes(int *j, int *i, char *line, t_par *par)
{
	if (par->flag == 5)
		new_line(par, j);
	if (line[*i] == 34)
	{
		check_symb(i, par);
		in_double_quotes(i, line, par, j);
	}
	else if (line[*i] == 39)
	{
		par->flag = 0;
		*i = *i + 1;
		while (line[*i] != 39 && line[*i] != '\0')
			print_symbol(par, line[*i], *j, i);
		if (line[*i] == 39 && line[*i + 1] == ' ')
		{
			*i = *i + 1;
			while (line[*i] == ' ' && line[*i] != '\0')
				*i = *i + 1;
			if (line[*i] != '\0')
				new_line(par, j);
			par->flag = 8;
		}
		else
			*i = *i + 1;
	}
}

void	write_special_dollar(t_par *par, char c, int j)
{
	char *tmp;

	tmp = par->str_na[j];
	par->str_na[j] = ft_strjoin_mod(par->str_na[j], '(');
	free(tmp);
	tmp = par->str_na[j];
	par->str_na[j] = ft_strjoin_mod(par->str_na[j], c);
	free(tmp);
	tmp = par->str_na[j];
	par->str_na[j] = ft_strjoin_mod(par->str_na[j], ')');
	free(tmp);
}

void	ft_main_par(t_par *par, char *line)
{
	int		i;
	int		j;
	int		h;
	int		count;

	j = 0;
	count = 0;
	h = size_of_mas_par_str(line);
	par->str_na = (char**)malloc(sizeof(char *) * (h + 1));
	i = 0;
	par->str_na[j] = malloc(sizeof(char) * 1);
	par->str_na[j][0] = '\0';
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		par->flag = 0;
		if (line[i] != 39 && line[i] != 34)
			no_in_quotes(&j, &i, line, par);
		if (line[i] == 34 || line[i] == 39)
			in_quotes(&j, &i, line, par);
	}
	par->str_na[j + 1] = NULL;
	free(line);
}

char	**parsing(char *line, t_par *par)
{
	ft_main_par(par, line);
	return (par->str_na);
}
