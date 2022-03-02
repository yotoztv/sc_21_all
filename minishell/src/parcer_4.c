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

int		check_command(char c)
{
	if (c == '|' || c == '>' || c == ';'
	|| c == '<')
		return (1);
	return (0);
}

int		check_dollar(char c, char d)
{
	if (c == '$' && ((d >= 'A' && d <= 'Z') ||
	(d >= 'a' && d <= 'z') || d == '_' || d == '?'))
		return (1);
	return (0);
}

int		check_end_word(char c)
{
	if (c != 39 && c != 34 && c != ' '
	&& c != '\0')
		return (1);
	return (0);
}

void	print_symbol(t_par *par, char c, int j, int *i)
{
	par->str_na[j] = ft_strjoin_mod_free(par->str_na[j], c);
	*i = *i + 1;
}

void	skip_space(char *line, int *i, t_par *par, int *j)
{
	while (line[*i] == ' ')
		*i = *i + 1;
	if (line[*i] != '\0')
		new_line(par, j);
	par->flag = 9;
}
