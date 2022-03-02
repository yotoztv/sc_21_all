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

int		ft_strnstr_mod(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (needle && needle[0] == '\0')
		return (0);
	j = 0;
	while (haystack[j] != '\0' && len >= ft_strlen(needle)
		&& (j + ft_strlen(needle) <= len))
	{
		i = 0;
		n = j;
		while (needle[i] != '\0' && haystack[n] == needle[i])
		{
			i++;
			n++;
		}
		if (i == ft_strlen(needle))
			return (j);
		j++;
	}
	return (-1);
}

void	qt_comands(t_par *par)
{
	char	**t;

	par->time_str = copy_mtrx_x(par);
	t = par->time_str;
	value_of_var(par);
	if (*t && ft_memcmp("echo", *t, (1 + ft_strlen("echo"))) == 0)
		na_echo(par);
	else if (*t && ft_memcmp("pwd", *t, (1 + ft_strlen("pwd"))) == 0)
		my_pwd(par);
	else if (*t && ft_memcmp("exit", *t, (1 + ft_strlen("exit"))) == 0)
		my_exit(par);
	else if (*t && ft_memcmp("cd", *t, (1 + ft_strlen("cd"))) == 0)
		my_cd(par);
	else if (*t && ft_memcmp("env", *t, (1 + ft_strlen("env"))) == 0)
		na_show_env(par);
	else if (*t && ft_memcmp("unset", *t, (1 + ft_strlen("unset"))) == 0)
		my_unset(par);
	else if (*t && ft_memcmp("export", *t, (1 + ft_strlen("export"))) == 0)
		par->env = my_export(par);
	else
		my_execve(par);
	qt_close_fds(par);
	ft_free_mtrx(t);
}

void	preview(void)
{
	ft_putstr_fd("oil_shell$ ", 1);
}

int		check_space(char *line)
{
	int	i;
	int	probel;

	i = 0;
	probel = 0;
	if (line[0] == '\0')
	{
		free(line);
		return (1);
	}
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			probel++;
		i++;
	}
	if (probel != i)
		return (0);
	else
	{
		free(line);
		return (1);
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	*str;
	t_par	par;
	char	*line;

	g_dochka = 0;
	preview();
	if (argc > 20000)
		return (0);
	str = argv[1];
	str = environ[1];
	line = argv[1];
	par.i = 0;
	par = init_start(par);
	par = copy_env(environ, par);
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, &ctrl_sl);
	while (1)
	{
		if (get_next_line(&line) == 0)
			exit(100);
		if (check_space(line) == 0)
			parser_simple_z(line, &par);
		preview();
	}
	return (0);
}
