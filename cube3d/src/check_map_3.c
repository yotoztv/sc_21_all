/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:54:54 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:55:12 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_par	find_rezolution_2(t_par par)
{
	par.i8++;
	while (par.map[par.j8][par.i8] == ' ' && (par.map[par.j8][par.i8]))
		par.i8++;
	while (ft_isdigit(par.map[par.j8][par.i8]) && par.rez_grz == 0)
	{
		if (par.kik8 < 100000)
			par.kik8 = par.kik8 * 10 + par.map[par.j8][par.i8] - '0';
		par.map[par.j8][par.i8++] = ' ';
	}
	par.rez_grz = par.kik8;
	par.kik8 = 0;
	while (par.map[par.j8][par.i8] == ' ' && (par.map[par.j8][par.i8]))
		par.i8++;
	while (ft_isdigit(par.map[par.j8][par.i8]) && par.rez_vrt == 0)
	{
		if (par.kik8 < 100000)
			par.kik8 = par.kik8 * 10 + par.map[par.j8][par.i8] - '0';
		par.map[par.j8][par.i8++] = ' ';
	}
	par.rez_vrt = par.kik8;
	if ((par.k8 == 1 && ((par.rez_vrt == 0) != par.rez_grz == 0)))
		exit_program_zero(par,
			"Error\n No valid rezolution parametres Example (R 1024 768) \n");
	par = corect_rez(par);
	return (par);
}

t_par	find_rezolution(t_par par)
{
	while (par.j8 < par.ymap_start)
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] == 'R' && (par.map[par.j8][par.i8]))
			{
				par.map[par.j8][par.i8] = ' ';
				par.k8++;
			}
			else
			{
				par.i8++;
				continue;
			}
			par = find_rezolution_2(par);
			par.i8++;
		}
		par.j8++;
	}
	if (par.k8 == 0 || par.k8 > 1)
		exit_program_zero(par, "Error\n R - not found or more then 1 \n");
	return (par);
}

int		rgbtoint(t_par par)
{
	int num;

	if ((par.r_c < 0 || par.g_c < 0 || par.b_c < 0)
		|| (par.r_c > 255 || par.g_c > 255 || par.b_c > 255))
		exit_program_zero(par,
			"Error\n Need valid value of color (from 0 to 255 included) \n");
	num = (par.r_c / 16) * pow(16, 5) + (par.r_c % 16) * pow(16, 4) +
		(par.g_c / 16) * pow(16, 3) + (par.g_c % 16) * pow(16, 2) +
		(par.b_c / 16) * 16 + (par.b_c % 16);
	return (num);
}
