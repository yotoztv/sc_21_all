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

void	pars_simp_22(t_par *par, int *status)
{
	pipe(par->fd);
	par->pid = fork();
	g_dochka = 1;
	if (par->pid == 0)
	{
		if (par->fd[0] >= 3)
			close(par->fd[0]);
		dup2(par->fd[1], 1);
		if (par->fd[1] >= 3)
			close(par->fd[1]);
		qt_riderect(par);
		exit(par->code_of_error_2);
	}
	if (par->pid > 0)
	{
		waitpid(par->pid, status, WUNTRACED);
		g_dochka = 0;
		if (par->fd[1] >= 3)
			close(par->fd[1]);
		dup2(par->fd[0], 0);
		if (par->fd[0] >= 3)
			close(par->fd[0]);
	}
	par->str = par->del_str + 1;
	par->flag_zero++;
}

void	pars_simp_334(t_par *par)
{
	if (par->fd[0] >= 3)
		close(par->fd[0]);
	dup2(par->fd[1], 1);
	if (par->fd[1] >= 3)
		close(par->fd[1]);
	qt_riderect(par);
	exit(par->code_of_error_2);
}

void	pars_simp_33(t_par *par, int *status)
{
	par->pars_fl = 0;
	par->pid = fork();
	g_dochka = 1;
	if (par->pid == 0)
		pars_simp_334(par);
	if (par->pid > 0)
	{
		waitpid(par->pid, status, WUNTRACED);
		if (WIFEXITED(status))
			par->code_of_error_2 = WEXITSTATUS(status);
		g_dochka = 0;
		if (par->fd[1] >= 3)
			close(par->fd[1]);
		dup2(par->fd[0], 0);
		if (par->fd[0] >= 3)
			close(par->fd[0]);
	}
	dup2(par->stdin, 0);
	dup2(par->stdout, 1);
}

void	parser_simple(t_par *par)
{
	char	**tmp;
	int		status;

	par->pars_fl = 1;
	par->flag_zero = 1;
	if (*par->str == NULL)
		par->str = NULL;
	par->i = 0;
	tmp = par->str;
	while (par->pars_fl == 1)
	{
		par->del_str = next_point_pipe(par->str);
		if (print_syntax(par) == 1)
			break ;
		if (par->del_str != 0)
			pars_simp_22(par, &status);
		else if (par->flag_zero > 1)
			pars_simp_33(par, &status);
		if (par->flag_zero == 1)
		{
			qt_riderect(par);
			par->pars_fl = 0;
			break ;
		}
	}
}
