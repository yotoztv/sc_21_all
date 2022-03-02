/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitls_34.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/23 13:50:51 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_mas(char **mas)
{
	int	j;

	j = 0;
	while (mas[j])
	{
		free(mas[j]);
		j++;
	}
	free(mas);
}

void	show_time_str(char **mtrx)
{
	int	i;

	i = 0;
	while (mtrx[i] !=  (void *)0)
	{
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(mtrx[i], 2);
		i++;
	}
}

void	ft_free_mtrx(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

int		get_next_line(char **line)
{
	char	buf[2];
	char	*str;
	int		i;

	*line = (char*)malloc(1);
	*line[0] = '\0';
	while ((i = read(0, buf, 1)) >= 0)
	{
		if (i == 0 && *line[0] == '\0')
			return (0);
		buf[1] = '\0';
		if (*buf == '\n')
			return (1);
		str = *line;
		*line = ft_strjoin(*line, buf);
		free(str);
		buf[0] = '\0';
	}
	return (0);
}
