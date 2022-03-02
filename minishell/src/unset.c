/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 17:19:27 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_find(t_par *par, int *p, int *o, int *flag)
{
	int	j;

	j = 1;
	while (par->time_str[j])
	{
		if (parcer_unset(par, j, p) == 0)
		{
			if (find_str(par->env[*o], par->time_str[j]) != -1
			&& par->time_str[j][0] != '\0')
				*flag = 1;
		}
		j++;
	}
}

void	ft_check_valid_un_exp(t_par *par)
{
	int j;
	int p;

	j = 0;
	p = 0;
	while (par->time_str[j])
	{
		if (parcer_unset(par, j, &p) != 0)
		{
			par->code_of_error_2 = 1;
			ft_putstr_fd("error: ", 1);
			ft_putstr_fd(par->time_str[j], 1);
			ft_putendl_fd(" not a valid identifier", 1);
		}
		else
			par->code_of_error_2 = 0;
		j++;
	}
}

void	main_unset(t_par *par, int o, int n)
{
	char	**environ;
	int		flag;
	int		p;

	environ = (char **)malloc(sizeof(char *) * (count_unset(par) + 1));
	ft_check_valid_un_exp(par);
	while (par->env[o])
	{
		p = 0;
		flag = 0;
		unset_find(par, &p, &o, &flag);
		if (flag != 1)
		{
			environ[n] = ft_strdup(par->env[o]);
			n++;
		}
		o++;
	}
	environ[n] = NULL;
	free_mas(par->env);
	par->env = environ;
}

void	my_unset(t_par *par)
{
	int	j;
	int	o;
	int	p;
	int	n;

	o = 0;
	n = 0;
	p = 0;
	j = basic_count(par->time_str, 0);
	if (j != 1)
		main_unset(par, o, n);
}
