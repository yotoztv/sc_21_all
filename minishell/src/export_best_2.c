/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_best_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:11:15 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 21:11:46 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_two(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

char	*ft_find_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	name = ft_calloc(sizeof(char), 1);
	while (str[i] != '\0' && str[i] != '=')
	{
		name = ft_strjoin_mod_free(name, str[i]);
		i++;
	}
	return (name);
}

void	write_error_inf(char *str, t_par *par)
{
	par->code_of_error_2 = 1;
	ft_putstr_fd("error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putendl_fd(" not a valid identifier", 1);
}

void	left_base(int *flag)
{
	ft_putstr_fd("declare -x ", 1);
	*flag = 0;
}

int		ft_if_sort(char **str, int start, int end)
{
	while (start < end)
	{
		if ((ft_strncmp(str[start],
		str[start + 1], ft_strlen(str[start]) + 1)) > 0)
			return (0);
		start++;
	}
	return (1);
}
