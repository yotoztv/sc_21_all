/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:55:36 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:55:43 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_par	find_textures_2(t_par par)
{
	ft_bzero(par.str_rezult, 99);
	par.i8++;
	while (par.map[par.j8][par.i8] == ' ' && (par.map[par.j8][par.i8]))
		par.i8++;
	while ((ft_isascii(par.map[par.j8][par.i8]))
		&& par.map[par.j8][par.i8] != ' ' && (par.map[par.j8][par.i8]))
	{
		par.str_rezult[par.kik8++] = par.map[par.j8][par.i8];
		par.map[par.j8][par.i8++] = ' ';
	}
	par.str_rezult[par.kik8] = '\0';
	if (!(open(par.str_rezult, O_RDONLY)) && par.k8 == 1)
		exit_program_zero(par,
			"Error\nCan't read, example (NO ./pics/greystone.xpm) \n");
	return (par);
}

t_par	find_textures_3(t_par par)
{
	par.map[par.j8][par.i8] = ' ';
	par.map[par.j8][par.i8 + 1] = ' ';
	par.k8++;
	par.i8++;
	return (par);
}

t_par	find_textures(t_par par, char *str)
{
	ft_bzero(par.str_rezult, 99);
	while (par.j8 < par.ymap_start)
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] == str[0] &&
			par.map[par.j8][par.i8 + 1] == str[1])
				par = find_textures_3(par);
			else
			{
				par.i8++;
				continue;
			}
			par = find_textures_2(par);
			par.i8++;
		}
		par.j8++;
	}
	if (par.k8 == 0 || par.k8 > 1)
		exit_program_zero(par,
			"Error\nSPEC texture (NO, SO, WE, EA, S, L1) not found \n");
	return (par);
}
