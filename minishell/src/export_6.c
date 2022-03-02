/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:05:51 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_check_more_var(char **environ, char *str, char *str2, int *n)
{
	int	o;
	int	l;

	o = 0;
	l = 0;
	while (environ[o])
	{
		if (find_str(environ[o], str) != -1)
			break ;
		o++;
	}
	if (o == basic_count(environ, l))
	{
		environ[*n] = ft_strdup(str2);
		*n = *n + 1;
	}
}

int		check_more_variable(t_par *par, char **environ, int j)
{
	int	o;
	int	p;
	int	n;

	p = 0;
	j = 1;
	while (par->time_str[j])
	{
		n = 0;
		while (environ[n])
			n++;
		o = 0;
		j++;
	}
	return (p);
}

char	*start_value_ex(int *k, int *i, t_par *par, int *j)
{
	char	*str;

	*k = 0;
	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	*i = *i + 1;
	*i = (par->time_str[*j][*i] == '$' && par->time_str[*j][*i + 1] == ')')
	? *i + 2 : *i;
	return (str);
}
