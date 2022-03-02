/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:59:38 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:59:51 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void		get_num_col(t_par *par)
{
	char	*dst;

	dst = NULL;
	if (par->wall_nswe == 0)
		dst = par->ardr_tx1 + (par->h_y_color * par->line_len_tx_1 +
		par->h_x_color * (par->bits_per_p_tx_1 / 8));
	else if (par->wall_nswe == 1)
		dst = par->ardr_tx2 + (par->h_y_color * par->line_len_tx_2 +
		par->h_x_color * (par->bits_per_p_tx_2 / 8));
	else if (par->wall_nswe == 2)
		dst = par->ardr_tx3 + (par->h_y_color * par->line_len_tx_3 +
		par->h_x_color * (par->bits_per_p_tx_3 / 8));
	else if (par->wall_nswe == 3)
		dst = par->ardr_tx4 + (par->h_y_color * par->line_len_tx_4 +
		par->h_x_color * (par->bits_per_p_tx_4 / 8));
	else
		par->color = 0x00000000;
	par->color = *(unsigned int*)dst;
}

void		find_possition_h_y(t_par *par)
{
	int		a;
	int		hw;
	int		delta_y;

	hw = par->high_wall;
	a = (par->rez_vrt - hw) / 2;
	delta_y = par->next_ray_y - a;
	if (delta_y > (par->high_wall / 2))
		delta_y = delta_y - (par->high_wall / 2);
	par->h_y_color = (delta_y * 63) / (par->high_wall / 2);
	if (par->h_y_color < 0 || par->h_y_color > 63)
		par->h_y_color = abs(par->h_y_color);
}

void		find_possition_h_x(t_par *par)
{
	float	x_float;
	int		x_int;

	if (par->wall_nswe == 0 || par->wall_nswe == 1)
		x_float = (par->crossx - (int)par->crossx);
	else if (par->wall_nswe == 2 || par->wall_nswe == 3)
		x_float = (par->crossy - (int)par->crossy);
	else
		x_float = 0;
	x_int = (x_float * 1000);
	if (x_int > 1000 / 2)
		x_int = x_int - (1000 / 2);
	par->h_x_color = (x_int * 63) / 500;
}

void		find_color(t_par *par)
{
	find_possition_h_y(par);
	get_num_col(par);
}
