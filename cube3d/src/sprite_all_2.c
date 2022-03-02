/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_all_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:02:58 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:03:06 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void		get_num_col_c_sp(t_par *par, int x_s_x, int h_s_y)
{
	char	*dst;

	if (par->sp_type[par->s_id] == 2)
		dst = par->ardr_txb + (h_s_y * par->line_len_tx_b +
		x_s_x * (par->bits_per_p_tx_b / 8));
	if (par->sp_type[par->s_id] == 7)
		dst = par->ardr_txf + (h_s_y * par->line_len_tx_f +
		x_s_x * (par->bits_per_p_tx_f / 8));
	if (dst == NULL)
		par->color = -1;
	else
		par->color_888 = *(unsigned int*)dst;
}

void		find_possition_h_s_y(t_par *par)
{
	int		result;
	float	sum;
	float	v;
	float	w;

	v = par->y55 - par->a_25;
	w = par->z_25 - par->a_25;
	sum = v / w;
	sum = 63 * (sum);
	result = sum;
	par->h_s_y = result;
}

int			find_possition_h_s_x(t_par *par)
{
	float	y_new;
	int		x_s_x;
	float	ostatok;

	y_new = coord_rotate_y(par->cross_x_sp1[par->s_id],
	par->cross_y_sp1[par->s_id], 2 * M_PI - par->feta[par->s_id]);
	ostatok = y_new - (int)y_new;
	x_s_x = (ostatok - 0.4) / 0.2 * 63;
	return (x_s_x);
}

void		draw_next_sp(t_par *par)
{
	int		a;
	int		z;

	par->x_s_x = find_possition_h_s_x(par);
	if (par->len_sp1[par->s_id] < 0.01)
		par->len_sp1[par->s_id] = 0.01;
	par->h55 = (par->rez_vrt * 0.3) / par->len_sp1[par->s_id];
	a = (par->rez_vrt - par->h55) / 2;
	z = a + par->h55;
	par->a_25 = a;
	par->z_25 = z;
	if (par->h55 >= par->rez_vrt)
		a = 0;
	if (par->h55 >= par->rez_vrt)
		z = par->rez_vrt - 1;
	par->y55 = a;
	while (par->y55 < (z - 1))
	{
		find_possition_h_s_y(par);
		get_num_col_c_sp(par, par->x_s_x, par->h_s_y);
		if (par->color_888 != 0x00111111 &&
		par->h_s_y > 4 && par->x_s_x > 4 && par->x_s_x < 59)
			my_mlx_pixel_put(par, par->ih, par->y55, par->color_888);
		par->y55++;
	}
}
