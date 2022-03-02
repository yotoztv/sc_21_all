/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:56:02 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:56:09 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		check_second_sp(t_par par, char c)
{
	par = init_i8_j8_k8_kik8(par);
	par.j8 = par.ymap_start;
	while (par.map[par.j8])
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] == c)
				return (1);
			par.i8++;
		}
		par.j8++;
	}
	return (0);
}

t_par	texture_list(t_par par)
{
	par = init_i8_j8_k8_kik8(par);
	par = find_textures(par, "NO");
	par.rel_path_tx1 = ft_strdup(par.str_rezult);
	par = init_i8_j8_k8_kik8(par);
	par = find_textures(par, "SO");
	par.rel_path_tx2 = ft_strdup(par.str_rezult);
	par = init_i8_j8_k8_kik8(par);
	par = find_textures(par, "WE");
	par.rel_path_tx3 = ft_strdup(par.str_rezult);
	par = init_i8_j8_k8_kik8(par);
	par = find_textures(par, "EA");
	par.rel_path_tx4 = ft_strdup(par.str_rezult);
	if (check_second_sp(par, '2') == 1)
	{
		par = init_i8_j8_k8_kik8(par);
		par = find_textures(par, "S ");
		par.rel_path_txb = ft_strdup(par.str_rezult);
	}
	if (check_second_sp(par, '7') == 1)
	{
		par = init_i8_j8_k8_kik8(par);
		par = find_textures(par, "L1");
		par.rel_path_txf = ft_strdup(par.str_rezult);
	}
	return (par);
}

t_par	check_trash(t_par par)
{
	par = init_i8_j8_k8_kik8(par);
	while (par.j8 < par.ymap_start)
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] != ' ')
			{
				ft_putstr_fd("Error\nExtra characters in map's file\n", 1);
				par.k8++;
			}
			par.i8++;
		}
		par.j8++;
	}
	if (par.k8 > 1)
		exit_program_zero(par, "Error\nTrash symbols in config part of file\n");
	ft_putstr_fd("Сonfig part loaded \n", 1);
	return (par);
}

int		check_1_0_2_7(char c)
{
	if (c == '1' || c == '0' || c == '2' || c == '7' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (7);
	return (0);
}

int		check_round(t_par par)
{
	if (par.map[par.j8][par.i8] == '1' || par.map[par.j8][par.i8] == ' ')
		return (0);
	else if ((par.map[par.j8][par.i8 - 1] == ' ') ||
		(par.map[par.j8][par.i8 + 1] == ' ') ||
		(par.map[par.j8 - 1][par.i8] == ' ') ||
		(par.map[par.j8 + 1][par.i8] == ' '))
		return (1);
	return (0);
}
