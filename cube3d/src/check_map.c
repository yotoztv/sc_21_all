/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:53:27 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:39:24 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		check_top_wall(t_par par)
{
	while (par.map[par.j8][par.i8])
	{
		if ((par.map[par.j8][par.i8] == ' ') ||
				(par.map[par.j8][par.i8] == '1'))
			par.i8++;
		else
			return (1);
	}
	return (0);
}

t_par	closed_map_2(t_par par)
{
	if (check_1_0_2_7(par.map[par.j8][par.i8]) == 0)
		exit_program_zero(par,
			"Error\nExcess symbol (must be -> 0 1 2 7 N S W E or Space) \n");
	if (check_1_0_2_7(par.map[par.j8][par.i8]) == 7)
		par.k8++;
	if (check_round(par) == 1)
		exit_program_zero(par, "Error\nMap not closed, sory. Check your map\n");
	return (par);
}

int		check_string_space(t_par par)
{
	int	i;

	i = 0;
	while (par.map[par.j8][i])
	{
		if (par.map[par.j8][i] == ' ')
			i++;
		else
			return (0);
	}
	if (i == 50)
		return (1);
	else
		return (0);
}

t_par	closed_map(t_par par)
{
	par = init_i8_j8_k8_kik8(par);
	par.j8 = par.ymap_start;
	if (check_top_wall(par) == 1)
		exit_program_zero(par, "Error\n Map wrong, sory. Check Top of Map/n");
	par.j8++;
	while (par.map[par.j8 + 1])
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			par = closed_map_2(par);
			par.i8++;
			continue;
		}
		if (check_string_space(par) == 1)
			exit_program_zero(par, "Error\nMap wrong, empty string into Map/n");
		par.j8++;
	}
	par.i8 = 0;
	if (check_top_wall(par) == 1)
		exit_program_zero(par, "Error\nMap not closed. Check Bottom of map/n");
	if (par.k8 != 1)
		exit_program_zero(par, "Error\nWrong player position (N S W E)/n");
	ft_putstr_fd("Map corect loaded \n", 1);
	return (par);
}

t_par	check_valid_map(t_par par)
{
	par = init_i8_j8_k8_kik8(par);
	par = find_start_map(par);
	par.rez_grz = 0;
	par.rez_vrt = 0;
	par = init_i8_j8_k8_kik8(par);
	par = find_rezolution(par);
	par = init_i8_j8_k8_kik8(par);
	par = find_floor_color(par, 'F');
	par.color_floor = rgbtoint(par);
	par = init_i8_j8_k8_kik8(par);
	par = find_floor_color(par, 'C');
	par.color_cell = rgbtoint(par);
	par = texture_list(par);
	check_trash(par);
	par = closed_map(par);
	par = parser_pl(par);
	return (par);
}
