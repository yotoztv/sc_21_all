/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_4_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:46:13 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 21:46:30 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_par	find_floor_color_3(t_par par, int color)
{
	if (ft_isdigit(par.map[par.j8][par.i8]))
	{
		while (ft_isdigit(par.map[par.j8][par.i8]) && color < 0)
		{
			par.kik8 = par.kik8 * 10 + par.map[par.j8][par.i8] - '0';
			par.map[par.j8][par.i8] = ' ';
			par.i8++;
		}
		par.color_rezult = par.kik8;
	}
	else
		par.color_rezult = -1;
	return (par);
}

t_par	find_floor_color_2(t_par par)
{
	par.i8++;
	while (par.map[par.j8][par.i8] == ' ' && (par.map[par.j8][par.i8]))
		par.i8++;
	par = find_floor_color_3(par, par.r_c);
	par.r_c = par.color_rezult;
	par.kik8 = 0;
	if (par.map[par.j8][par.i8] == ',' && (par.map[par.j8][par.i8]))
		par.map[par.j8][par.i8++] = ' ';
	par = find_floor_color_3(par, par.g_c);
	par.g_c = par.color_rezult;
	par.kik8 = 0;
	if (par.map[par.j8][par.i8] == ',' && (par.map[par.j8][par.i8]))
		par.map[par.j8][par.i8++] = ' ';
	par = find_floor_color_3(par, par.b_c);
	par.b_c = par.color_rezult;
	if (par.k8 == 1 && ((par.r_c < 0 || par.g_c < 0) || par.b_c < 0))
		exit_program_zero(par,
			"Error\nNo valid color (F/C) Example (F 255,0,14) \n");
	return (par);
}

t_par	find_floor_color(t_par par, char c)
{
	while (par.j8 < par.ymap_start)
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] == c && (par.map[par.j8][par.i8]))
			{
				par.map[par.j8][par.i8] = ' ';
				par.k8++;
			}
			else
			{
				par.i8++;
				continue;
			}
			par = find_floor_color_2(par);
			par.i8++;
		}
		par.j8++;
	}
	if (par.k8 == 0 || par.k8 > 1)
		exit_program_zero(par, "Error\nColor not found (F/C) \n");
	return (par);
}
