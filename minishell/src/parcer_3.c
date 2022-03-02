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

void	init_some(int *count, int *flag)
{
	*count = (*flag == 5) ? *count + 1 : *count;
	*flag = 0;
}

void	no_in_quotes_count(int *count, int *i, int *flag, char *line)
{
	while (check_no_quotes(line[*i]) == 1)
	{
		init_some(count, flag);
		if (line[*i] == 92)
			*i = *i + 2;
		else if (check_command(line[*i]) == 1)
		{
			if (*i != 0)
				*count = (line[*i - 1] != ' ') ? *count + 1 : *count;
			*count = (line[*i - 1] != ' ') ? *count + 1 : *count;
			if (line[*i] == '>' && line[*i + 1] == '>')
				*i = *i + 1;
			*i = *i + 1;
			*flag = 5;
		}
		else
			*i = *i + 1;
	}
	if (line[*i] == ' ')
	{
		while (line[*i] == ' ' && line[*i] != ';')
			*i = *i + 1;
		*count = (line[*i] != '\0') ? *count + 1 : *count;
		*flag = 9;
	}
}

void	in_double_quotes_count(int *count, int *i, int *flag, char *line)
{
	while (line[*i] != 34 && line[*i] != '\0')
	{
		*flag = 0;
		if (line[*i] == 92)
		{
			if (line[*i + 1] == 34)
				*flag = 2;
			if (line[*i] == 92 && line[*i + 1] == 92)
			{
				*i = *i + 1;
				*flag = 3;
			}
		}
		*i = (*flag == 2) ? *i + 1 : *i;
		*i = *i + 1;
	}
	if (line[*i] == 34 && line[*i + 1] == ' ')
	{
		*i = *i + 1;
		while (line[*i] == ' ' && line[*i] != '\0')
			*i = *i + 1;
		*count = (line[*i] != '\0') ? *count + 1 : *count;
	}
	else
		*i = *i + 1;
}

void	in_one_quotes_count(int *count, int *i, int *flag, char *line)
{
	*i = *i + 1;
	*flag = 0;
	while (line[*i] != 39 && line[*i] != '\0')
		*i = *i + 1;
	if (line[*i] == 39 && line[*i + 1] == ' ')
	{
		*i = *i + 1;
		while (line[*i] == ' ' && line[*i] != '\0')
			*i = *i + 1;
		*count = (line[*i] != '\0') ? *count + 1 : *count;
		*flag = 8;
	}
	else
		*i = *i + 1;
}

void	in_quotes_count(int *count, int *i, int *flag, char *line)
{
	if (*flag == 5)
		*count = *count + 1;
	if (line[*i] == 34)
	{
		*i = *i + 1;
		in_double_quotes_count(count, i, flag, line);
	}
	else if (line[*i] == 39)
		in_one_quotes_count(count, i, flag, line);
}
