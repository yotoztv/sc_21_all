/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:56:14 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_oldpwd(t_par *par, int j)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (par->env[j])
	{
		if (ft_strnstr_mod(par->env[j], "PWD=", ft_strlen(par->env[j])) == 0)
		{
			str = ft_strjoin_and_free(str, par->env[j] + 4);
			break ;
		}
		j++;
	}
	j = 0;
	while (par->env[j])
	{
		if (ft_strnstr_mod(par->env[j], "OLDPWD=", ft_strlen(par->env[j])) == 0)
		{
			free(par->env[j]);
			par->env[j] = ft_strjoin("OLDPWD=", str);
			break ;
		}
		j++;
	}
	free(str);
}

char	*find_home(t_par *par)
{
	int		j;
	char	*home_str;

	j = 0;
	while (par->env[j])
	{
		if (ft_strnstr_mod(par->env[j], "HOME=", ft_strlen(par->env[j])) == 0)
		{
			home_str = par->env[j] + 5;
			return (home_str);
		}
		j++;
	}
	return (NULL);
}

void	write_error_cd(char *argt, t_par *par)
{
	par->code_of_error_2 = 1;
	ft_putstr_fd("oil_shell: cd: ", 1);
	ft_putstr_fd(argt, 1);
	ft_putstr_fd(": No such file or directory\n", 1);
}

void	cd_without_arg(char *home_str, t_par *par, int j)
{
	if ((home_str = find_home(par)) == NULL)
		ft_putendl_fd("oil_shell: cd: HOME not set", 2);
	else
	{
		j = 0;
		if (chdir(home_str) == 0)
		{
			par->code_of_error_2 = 0;
			change_oldpwd(par, 0);
			while (par->env[j])
			{
				if (ft_strnstr_mod(par->env[j], "PWD=",
				ft_strlen(par->env[j])) == 0)
				{
					free(par->env[j]);
					par->env[j] = ft_strjoin("PWD=", home_str);
				}
				j++;
			}
		}
		else
			write_error_cd(home_str, par);
	}
}

int		check_dot(char *argt)
{
	if (ft_strnstr_mod(argt, "..", ft_strlen(argt)) < 0 &&
		ft_strnstr_mod(argt, ".", ft_strlen(argt)) < 0)
		return (1);
	else
		return (0);
}
