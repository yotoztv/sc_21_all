/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 17:02:49 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	calc_mm_i(t_par *par)
{
	par->mm_i = 0;
	par->mm_i2 = 0;
	while (par->str)
	{
		if (is_pipe(par->str[par->mm_i]) == 1 || !par->str[par->mm_i])
			break ;
		if (is_point(par->str[par->mm_i]) == 1)
			break ;
		if (is_riderects(par->str[par->mm_i], par) == 1)
			par->mm_i2 = par->mm_i2 - 2;
		par->mm_i++;
		par->mm_i2++;
	}
}

char	**copy_mtrx_x(t_par *par)
{
	int		k;
	int		m;
	char	**mtrx;

	calc_mm_i(par);
	if (par->mm_i == 0)
		return (NULL);
	if (!(mtrx = (char **)malloc(sizeof(char *) * (par->mm_i2 + 1))))
		return (NULL);
	k = 0;
	m = 0;
	while (m != par->mm_i2)
	{
		if (is_riderects(par->str[k], par) == 1)
		{
			k += 2;
			continue;
		}
		mtrx[m] = ft_strdup(par->str[k]);
		m++;
		k++;
	}
	mtrx[m] = NULL;
	return (mtrx);
}

char	**copy_mtrx(char **mass)
{
	int		i;
	int		k;
	char	**mtrx;

	i = 0;
	while (mass[i])
		i++;
	if (i == 0)
		return (NULL);
	if (!(mtrx = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	k = 0;
	while (k != i)
	{
		mtrx[k] = ft_strdup(mass[k]);
		k++;
	}
	mtrx[k] = NULL;
	return (mtrx);
}
