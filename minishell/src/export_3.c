/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 20:41:33 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_prew(t_par *par, int j)
{
	int	i;

	i = 0;
	while (i < j && par->time_str[j])
	{
		if ((ft_strncmp(par->time_str[i], par->time_str[j],
		ft_strlen(par->time_str[i]) + 1) == 0))
			return (1);
		i++;
	}
	return (0);
}

int		check_prew_more(t_par *par, int j, char **environ)
{
	int		i;
	int		u;
	char	*str;

	i = 0;
	u = 0;
	while (par->time_str[j][u] != '\0' && par->time_str[j][u] != '=')
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		str = ft_strjoin_mod_free(str, par->time_str[j][u]);
		u++;
	}
	while (environ[i])
	{
		if ((ft_strncmp(environ[i], str,
		ft_strlen(environ[i]) + 1) == 0))
			return (1);
		i++;
	}
	return (0);
}

int		parcer_of_export_mod(t_par *par, int j)
{
	int		i;
	char	*str;

	i = 0;
	str = define_str(par, j, &i);
	if (ft_strncmp(str, "error: not a valid identifier",
	ft_strlen(str) + 1) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int		count_add_lines(t_par *par, int flag, int o)
{
	int		j;
	char	*str;
	int		k;

	j = 1;
	k = 0;
	while (par->time_str[j])
	{
		flag = 0;
		if (check_prew(par, j) == 0 && parcer_of_export_mod(par, j) == 0)
		{
			o = 0;
			str = define_str(par, j, &o);
			while (par->env[o])
			{
				flag = (find_str(par->env[o], str) >= 0) ? -1 : 0;
				o++;
			}
			free(str);
			k = (flag != -1) ? k + 1 : k;
		}
		j++;
	}
	return (k);
}

int		count_of_str(t_par *par)
{
	int		j;
	int		o;
	int		k;

	k = 0;
	k = count_add_lines(par, 0, 0);
	o = 0;
	while (par->env[o])
		o++;
	j = 1;
	while (par->time_str[j])
		j++;
	return (o + k);
}
