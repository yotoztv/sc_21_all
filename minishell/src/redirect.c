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

void	qt_close_fds(t_par *par)
{
	if (par->fd[1] >= 3)
	{
		close(par->fd[1]);
		dup2(par->stdout, 1);
	}
	if (par->fd[0] >= 3)
	{
		close(par->fd[0]);
		dup2(par->stdin, 0);
	}
}

void	qt_open_close(t_par *par)
{
	if (par->rid_type == 1)
	{
		if (par->fd[1] >= 3)
			close(par->fd[1]);
		par->fd[1] = open(par->file_name,
		O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		dup2(par->fd[1], 1);
	}
	else if (par->rid_type == 2)
	{
		if (par->fd[1] >= 3)
			close(par->fd[1]);
		par->fd[1] = open(par->file_name,
		O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		dup2(par->fd[1], 1);
	}
	else if (par->rid_type == 3)
	{
		if (par->fd[0] >= 3)
			close(par->fd[0]);
		par->fd[0] = open(par->file_name, O_RDONLY, S_IRWXU);
		dup2(par->fd[0], 0);
	}
	free(par->file_name);
}

char	**next_point_riderect(char **str, t_par *par)
{
	char	**s;

	if (str ==  (void *)0)
		return (0);
	s = str;
	while (*s !=  (void *)0)
	{
		if (is_pipe(*s) == 1)
			break ;
		if (is_point(*s) == 1)
			break ;
		if (is_riderects(*s, par) == 1)
		{
			par->file_name = ft_strdup(*(s + 1));
			qt_open_close(par);
			return (s);
		}
		s++;
	}
	return (0);
}

void	qt_riderect(t_par *par)
{
	int		flag_2;
	char	**del_str_2;
	char	**orig_str;

	flag_2 = 1;
	orig_str = par->str;
	while (flag_2 == 1)
	{
		del_str_2 = next_point_riderect(par->str, par);
		if (del_str_2 != 0 && (is_pipe(del_str_2[1]) == 1
		|| is_point(del_str_2[1]) || is_riderects((del_str_2[1]), par)))
		{
			qt_close_fds(par);
			ft_putstr_fd("oil_shell: syntax error\n", 2);
			break ;
		}
		else if (del_str_2 != 0)
			par->str = del_str_2 + 1;
		else
		{
			par->str = orig_str;
			qt_comands(par);
			flag_2 = 0;
		}
	}
}
