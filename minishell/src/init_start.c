/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 17:56:27 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		print_syntax(t_par *par)
{
	if (par->del_str != 0 && (is_pipe(par->del_str[1]) == 1 ||
		is_point(par->del_str[1]) || is_riderects((par->del_str[1]), par)))
	{
		ft_putstr_fd("oil_shell: ", 2);
		ft_putstr_fd("syntax error\n", 2);
		return (1);
	}
	return (0);
}

int		check_in_sintax(t_par *par)
{
	if (is_pipe(par->str[0]) == 1 || is_riderects(par->str[0], par) == 1 ||
		is_point(par->str[0]) == 1)
	{
		ft_putstr_fd("oil_shell: ", 1);
		ft_putstr_fd("syntax error\n", 2);
		return (1);
	}
	return (0);
}

t_par	init_start(t_par par)
{
	par.stdin = dup(0);
	par.stdout = dup(1);
	par.fd[0] = 0;
	par.fd[1] = 1;
	par.dollar = 0;
	par.code_of_error = 0;
	par.code_of_error_2 = 0;
	return (par);
}

t_par	copy_env(char **env, t_par par)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	par.env = (char **)malloc(sizeof(char *) * (i + 1));
	par.env[i] = NULL;
	i = 0;
	while (env[i])
	{
		par.env[i] = ft_strdup(env[i]);
		i++;
	}
	return (par);
}
