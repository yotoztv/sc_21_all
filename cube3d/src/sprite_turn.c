/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:03:22 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:03:29 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int			cross_sqrt(float x, float y, float x_new, float y_new)
{
	float	indent;

	indent = 0.4;
	if (x_new > ((int)x + indent) && x_new < ((int)x + 1 - indent)
	&& y_new > ((int)y + indent) && y_new < ((int)y + 1 - indent))
		return (1);
	return (0);
}

float		coord_rotate_x(float x, float y, float feta)
{
	float	x_new;

	x_new = (x - ((int)x + 0.5)) * cos(feta) -
		(y - ((int)y + 0.5)) * sin(feta) + ((int)x + 0.5);
	return (x_new);
}

float		coord_rotate_y(float x, float y, float feta)
{
	float	y_new;

	y_new = (y - ((int)y + 0.5)) * cos(feta) +
		(x - ((int)x + 0.5)) * sin(feta) + ((int)y + 0.5);
	return (y_new);
}

int			find_cross_sqrt(t_par *par)
{
	float	x;
	float	y;
	float	x_new;
	float	y_new;
	int		cross_yes;

	x = par->crossx;
	y = par->crossy;
	x_new = coord_rotate_x(par->crossx,
		par->crossy, 2 * M_PI - par->feta[par->s_id]);
	y_new = coord_rotate_y(par->crossx,
		par->crossy, 2 * M_PI - par->feta[par->s_id]);
	cross_yes = cross_sqrt(par->crossx,
		par->crossy, x_new, y_new);
	return (cross_yes);
}
