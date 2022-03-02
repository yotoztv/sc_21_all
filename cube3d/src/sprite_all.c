/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:02:40 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:02:46 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void		draw_sprite(t_par *par)
{
	draw_next_sp(par);
	par->s_id--;
}

void		find_feta(t_par *par)
{
	par->feta[par->s_id] = atan2((par->crossy - par->dply),
		(par->crossx - par->dplx));
}

void		check_repeat(t_par *par)
{
	int		xi;
	int		yi;

	xi = (int)par->crossx;
	yi = (int)par->crossy;
	if (!((xi == par->current_sp_x) && (yi == par->current_sp_y)))
	{
		par->s_id++;
		par->cross_x_sp1[par->s_id] = par->crossx;
		par->cross_y_sp1[par->s_id] = par->crossy;
		par->current_sp_x = (int)par->crossx;
		par->current_sp_y = (int)par->crossy;
		find_feta(par);
		if (par->map[yi][xi] == '2')
			par->sp_type[par->s_id] = 2;
		else if (par->map[yi][xi] == '7')
			par->sp_type[par->s_id] = 7;
		par->len_sp1[par->s_id] =
			hypot((fabs(par->dplx) - fabs(par->current_sp_x + 0.5)),
			(fabs(par->dply) - fabs(par->current_sp_y + 0.5)));
	}
}

void		save_sp(t_par *par)
{
	if (find_cross_sqrt(par) == 1)
		check_repeat(par);
}
