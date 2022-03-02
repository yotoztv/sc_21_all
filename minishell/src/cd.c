/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:57:06 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wh_end_of_str(t_par *par, int *i, int *j)
{
	int	u;

	u = 0;
	while (par->env[*j][u] != '\0')
	{
		if (par->env[*j][u] == '/')
			*i = u;
		u++;
	}
	par->env[*j][*i] = '\0';
	if (*i == 4)
		par->env[*j] = ft_strjoin_mod_free(par->env[*j], '/');
}

void	cd_with_arg(char *argt, t_par *par, int j, int *i)
{
	if (chdir(argt) == 0)
	{
		if (ft_strncmp(argt, ".", 2) != 0)
			change_oldpwd(par, 0);
		while (par->env[j])
		{
			if (ft_strnstr_mod(par->env[j], "PWD=",
			ft_strlen(par->env[j])) == 0)
				break ;
			j++;
		}
		if (par->env[j] != NULL)
		{
			if ((check_dot(argt)) == 1)
			{
				if (par->env[j][5] != '\0')
					par->env[j] = ft_strjoin_mod_free(par->env[j], '/');
				par->env[j] = ft_strjoin_and_free(par->env[j], argt);
			}
			else if (ft_strnstr_mod(argt, "..", ft_strlen(argt)) == 0)
				wh_end_of_str(par, i, &j);
		}
	}
	else
		write_error_cd(argt, par);
}

void	my_cd(t_par *par)
{
	int		i;
	int		u;
	char	*home_str;
	char	*argt;

	home_str = NULL;
	i = 0;
	u = 0;
	while (par->str[i])
		i++;
	if (i > 1)
		argt = par->str[1];
	if (i == 1)
		cd_without_arg(home_str, par, 0);
	else
	{
		i = 0;
		cd_with_arg(argt, par, 0, &i);
	}
}
