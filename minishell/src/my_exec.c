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

char	*find_path(t_par *par)
{
	char	*str;
	int		i;

	i = 0;
	while (par->env[i])
	{
		if (ft_memcmp("PATH=", par->env[i], 5) == 0)
		{
			str = ft_strdup(par->env[i]);
			ft_memmove(str, (par->env[i] + 5),
			(ft_strlen(par->env[i] + 5) + 1));
			return (str);
		}
		i++;
	}
	return (ft_strdup(" : : :"));
}

char	*find_pwd_path(t_par *par)
{
	char	*str;
	int		i;

	i = 0;
	while (par->env[i])
	{
		if (ft_memcmp("PWD=", par->env[i], 4) == 0)
		{
			str = ft_strdup(par->env[i]);
			ft_memmove(str, (par->env[i] + 4),
			(ft_strlen(par->env[i] + 4) + 1));
			return (str);
		}
		i++;
	}
	return (NULL);
}

void	my_execve_2(t_par *par)
{
	par->str_path = find_path(par);
	par->tmp = par->str_path;
	par->mtrx_paths = ft_split(par->str_path, ':');
	free(par->str_path);
	if (par->str[0][0] != '/')
	{
		par->e_path = find_pwd_path(par);
		par->tmp = par->e_path;
		par->e_path = ft_strjoin(par->e_path, "/");
		free(par->tmp);
		par->tmp = par->e_path;
		par->e_path = ft_strjoin(par->e_path, par->str[0]);
		free(par->tmp);
	}
	else
	{
		ft_memmove(par->str[0], (par->str[0] + 0),
		(ft_strlen(par->str[0] + 0) + 1));
		par->e_path = ft_strdup(par->str[0]);
	}
}

void	exec_pid(t_par *par)
{
	int	i;

	i = 0;
	while (par->mtrx_paths[i] &&
	execve(par->e_path, par->time_str, par->env) == -1)
	{
		par->e_path = ft_strjoin("/", par->str[0]);
		par->tmp = par->e_path;
		par->e_path = ft_strjoin(par->mtrx_paths[i], par->e_path);
		free(par->tmp);
		i++;
	}
	ft_putstr_fd("oil_shell: ", 1);
	ft_putstr_fd(par->str[0], 2);
	ft_putstr_fd(" : command not found\n", 2);
	par->code_of_error = 127;
	exit(127);
}

void	my_execve(t_par *par)
{
	pid_t	pid;
	int		status;

	my_execve_2(par);
	pid = fork();
	g_dochka = 1;
	if (pid == 0)
		exec_pid(par);
	if (pid > 0)
	{
		waitpid(pid, &status, WUNTRACED);
		ft_free_mtrx(par->mtrx_paths);
		g_dochka = 0;
		if (WIFEXITED(status))
			par->code_of_error_2 = WEXITSTATUS(status);
		if (WTERMSIG(status) == 2)
			par->code_of_error_2 = 130;
		if (WTERMSIG(status) == 3)
			par->code_of_error_2 = 131;
	}
	free(par->e_path);
}
