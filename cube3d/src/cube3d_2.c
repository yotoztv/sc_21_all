/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:57:45 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:57:52 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	cross_wall_2(t_par *par)
{
	n_0_s_1_w_2_e_3_b_4(par);
	draw_next_ray(par);
	par->delta = par->delta + par->st_angle;
	par->len = 0;
	par->crossx = par->dplx;
	par->crossy = par->dply;
	par->cross_x0 = par->crossx;
	par->cross_y0 = par->crossy;
	par->ih++;
	par->current_sp_x = 0;
	par->current_sp_y = 0;
	par->s_id = 0;
	par->erka = 77;
}

void	cross_wall(t_par *par)
{
	int xi;
	int yi;

	xi = (int)par->crossx;
	yi = (int)par->crossy;
	if (!(par->map[yi][xi]))
		par->erka = -1;
	else if (par->ih >= par->rez_grz)
		par->erka = 1;
	else if (par->map[yi][xi] == '1' || par->map[yi][xi] == ' ')
		cross_wall_2(par);
	else if ((par->map[yi][xi] == '0') || (par->map[yi][xi] == '2')
		|| (par->map[yi][xi] == '7'))
	{
		if (!(par->map[yi][xi] == '0'))
			save_sp(par);
		par->cross_x0 = par->crossx;
		par->cross_y0 = par->crossy;
		par->erka = 0;
	}
}

void	find_cross(t_par *par)
{
	if (par->erka != 77)
	{
		par->alpha = (par->plazimt) * M_PI / 180;
		par->beta = (par->plazimt + par->delta) * M_PI / 180;
		par->st_cos = (par->st * cos(par->beta));
		par->st_sin = (par->st * sin(par->beta));
	}
	cross_wall(par);
	par->crossx = par->crossx + par->st_cos;
	par->crossy = par->crossy + par->st_sin;
	par->len = par->len + par->st;
}

t_par	parser_plsun(t_par par)
{
	if (par.plsun == 'N')
		par.plazimt = 270;
	if (par.plsun == 'E')
		par.plazimt = 0;
	if (par.plsun == 'S')
		par.plazimt = 90;
	if (par.plsun == 'W')
		par.plazimt = 180;
	return (par);
}
