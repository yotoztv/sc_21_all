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

char	**next_point_pipe(char **str)
{
	char **s;

	if (str == 0)
		return (0);
	s = str;
	while (*s)
	{
		if (is_point(*s) == 1)
			break ;
		if (is_pipe(*s) == 1)
			return (s);
		s++;
	}
	return (0);
}

char	**next_point_zap(t_par *par)
{
	char **s;

	if (par->str == (void *)0)
		return (0);
	s = par->str;
	while (*s != (void *)0)
	{
		if (is_point(*s) == 1)
		{
			par->str_next_zap = s;
			return (s);
		}
		s++;
	}
	return (0);
}
