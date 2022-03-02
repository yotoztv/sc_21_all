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

void	my_exit(t_par *par)
{
	int i;

	i = 0;
	while (par->time_str[i] && is_pipe(par->time_str[i]) == 0)
		i++;
	if (i == 1)
		exit(par->code_of_error);
	else if (i == 2 && is_str_num(par->str[1]) == 1)
		exit(ft_atoi(par->str[1]));
	else if (i > 2 && is_str_num(par->str[1]) == 1)
	{
		ft_putstr_fd("oil_shell: ", 1);
		ft_putstr_fd("exit: too many arguments\n", 1);
		par->code_of_error_2 = 1;
	}
	else
	{
		ft_putstr_fd("oil_shell:  exit:", 1);
		ft_putstr_fd(par->str[1], 1);
		ft_putstr_fd(": numeric argument required\n", 1);
		exit(255);
	}
}

void	my_pwd(t_par *par)
{
	char	*s;

	par->str = NULL;
	s = getcwd(NULL, 0);
	ft_putstr_fd(s, 1);
	free(s);
	ft_putstr_fd("\n", 1);
	par->code_of_error_2 = 0;
}

int		is_str_num(char *str)
{
	char	*str_num;

	str_num = str;
	while (*str_num != '\0')
	{
		if (ft_isdigit(*str_num) == 0)
			return (0);
		str_num++;
	}
	return (1);
}
