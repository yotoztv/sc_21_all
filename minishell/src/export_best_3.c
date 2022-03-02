/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_best_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:12:10 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:12:38 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sorting(char **str, int start, int size)
{
	int		s;
	int		e;
	char	*x;

	s = start;
	e = start + size;
	x = str[start + size / 2];
	while (s < e)
	{
		while (s < (size + start) &&
		(ft_strncmp(str[s], x, ft_strlen(x) + 1) < 0))
			s++;
		while (e > start && (ft_strncmp(str[e], x, ft_strlen(x) + 1) > 0))
			e--;
		if (s < e)
			change_two(str + s, str + e);
	}
	if (ft_if_sort(str, start, start + size))
		return (str);
	if (e > start + 1)
		str = sorting(str, 0, e);
	if (start + size > s + 1)
		str = sorting(str, s, start + size - s);
	return (str);
}

int		parcer_of_export(t_par *par, int j)
{
	int		i;

	i = 0;
	while (par->time_str[j][i] != '\0')
	{
		if (ft_isdigit(par->time_str[j][0]) == 1 || par->time_str[j][0] == '=')
			return (0);
		if (ft_isalpha(par->time_str[j][i]) == 0 &&
		ft_isdigit(par->time_str[j][i]) == 0 && par->time_str[j][i] != '_' &&
		par->time_str[j][i] != '=')
			return (0);
		i++;
	}
	if (par->time_str[j][0] == '\0')
		return (0);
	return (1);
}
