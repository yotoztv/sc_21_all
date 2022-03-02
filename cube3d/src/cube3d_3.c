/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:58:31 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:58:41 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void		draw_next_ray(t_par *par)
{
	par->xp = 30;
	par->yp = 63;
	par->next_ray_y = 0;
	par->len = par->len * cos(par->alpha - par->beta);
	par->hw_wall = (par->rez_vrt * 0.9) / par->len;
	par->high_wall = par->hw_wall;
	par->a_wall = (par->rez_vrt - par->hw_wall) / 2;
	par->z_wall = par->a_wall + par->hw_wall;
	if (par->hw_wall >= par->rez_vrt)
	{
		par->a_wall = 0;
		par->z_wall = par->rez_vrt + 1;
	}
	par->next_ray_y = par->a_wall;
	find_possition_h_x(par);
	while ((par->next_ray_y) < (par->z_wall - 1))
	{
		find_color(par);
		my_mlx_pixel_put(par, par->ih, par->next_ray_y, par->color);
		par->next_ray_y++;
	}
	while (par->s_id > 0)
		draw_sprite(par);
}

t_par		pl_step_left(t_par par)
{
	int		xi;
	int		yi;
	double	xd;
	double	yd;

	xd = par.dplx + par.pl_step_l * cos((par.plazimt + 90) * M_PI / 180);
	yd = par.dply + par.pl_step_l * sin((par.plazimt + 90) * M_PI / 180);
	xi = (int)xd;
	yi = (int)yd;
	if ((par.map[yi][xi] == '0')
		|| (par.map[yi][xi] == '2') || (par.map[yi][xi] == '7'))
	{
		par.dplx = xd;
		par.dply = yd;
	}
	return (par);
}

t_par		pl_step_forw(t_par par)
{
	int		xi;
	int		yi;
	double	xd;
	double	yd;

	xd = par.dplx + par.pl_step * cos(par.plazimt * M_PI / 180);
	yd = par.dply + par.pl_step * sin(par.plazimt * M_PI / 180);
	xi = (int)xd;
	yi = (int)yd;
	if ((par.map[yi][xi] == '0') || (par.map[yi][xi] == '2')
		|| (par.map[yi][xi] == '7'))
	{
		par.dplx = xd;
		par.dply = yd;
	}
	return (par);
}

void		n_0_s_1_w_2_e_3_b_4(t_par *par)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = (int)par->cross_x0;
	x2 = (int)par->crossx;
	y1 = (int)par->cross_y0;
	y2 = (int)par->crossy;
	if (x1 == x2 && y2 < y1)
		par->wall_nswe = 0;
	else if (x1 == x2 && y2 > y1)
		par->wall_nswe = 1;
	else if (y1 == y2 && x2 < x1)
		par->wall_nswe = 2;
	else if (y1 == y2 && x2 > x1)
		par->wall_nswe = 3;
}
