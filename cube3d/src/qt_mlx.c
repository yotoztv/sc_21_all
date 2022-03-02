/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:01:33 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:01:43 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	key_act_2(t_par *par, int keycode)
{
	if (keycode == 126)
	{
		par->pl_step = 0.5;
		*par = pl_step_forw(*par);
	}
	if (keycode == 125)
	{
		par->pl_step = -0.5;
		*par = pl_step_forw(*par);
	}
	if (keycode == 13)
	{
		par->pl_step = 0.1;
		*par = pl_step_forw(*par);
	}
	if (keycode == 1)
	{
		par->pl_step = -0.1;
		*par = pl_step_forw(*par);
	}
	if (keycode == 0)
	{
		par->pl_step_l = -0.1;
		*par = pl_step_left(*par);
	}
}

int		key_act(int keycode, t_par *par)
{
	mlx_destroy_image(par->mlx, par->img);
	par->img = mlx_new_image(par->mlx, par->rez_grz, par->rez_vrt);
	par->addr = mlx_get_data_addr(par->img, &par->bits_per_pixel,
		&par->line_length, &par->endian);
	if (keycode == 53)
	{
		mlx_destroy_window(par->mlx, par->win);
		ft_putstr_fd("I'm exit program by press ESC\n", 1);
		exit(0);
	}
	key_act_2(par, keycode);
	if (keycode == 2)
	{
		par->pl_step_l = 0.1;
		*par = pl_step_left(*par);
	}
	if (keycode == 123)
		par->plazimt = par->plazimt - 5;
	if (keycode == 124)
		par->plazimt = par->plazimt + 5;
	draw_raws(*par);
	return (0);
}

t_par	draw_raws(t_par par)
{
	int	i;

	par.current_sp_x = 0;
	par.current_sp_y = 0;
	par.s_id = 0;
	par.i = 0;
	paint_back(par);
	if (par.save_bmp == 0)
		mlx_put_image_to_window(par.mlx, par.win, par.img, 0, 0);
	i = 0;
	par.ih = 0;
	while (par.erka == 0 || par.erka == 77)
		find_cross(&par);
	paint_round_black(par);
	return (par);
}

t_par	draw_3d(t_par par)
{
	draw_raws(par);
	if (par.save_bmp == 1)
		screen_to_bmp(&par);
	mlx_hook(par.win, 17, 1L << 17, &exit_simple, &par);
	mlx_hook(par.win, 2, 1L << 0, &key_act, &par);
	mlx_loop(par.mlx);
	return (par);
}
