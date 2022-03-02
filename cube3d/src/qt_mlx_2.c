/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_mlx_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:01:55 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:02:04 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	exit_program_img(void)
{
	ft_putstr_fd("Error\n No load textures, check files", 1);
	exit(0);
}

int		exit_simple(t_par *par)
{
	ft_putstr_fd("I'm exit program\n", 1);
	mlx_destroy_window(par->mlx, par->win);
	exit(0);
	return (0);
}

void	paint_back(t_par par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < par.rez_vrt)
	{
		i = 0;
		while (i < par.rez_grz)
		{
			if (j < par.rez_vrt / 2)
				my_mlx_pixel_put(&par, i, j, par.color_cell);
			else
				my_mlx_pixel_put(&par, i, j, par.color_floor);
			i++;
		}
		j++;
	}
}

void	paint_round_black(t_par par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < par.rez_vrt)
	{
		i = 0;
		while (i < par.rez_grz)
		{
			if (j == 0 || j == (par.rez_vrt - 1) ||
				i == 0 || i == (par.rez_grz - 1))
				my_mlx_pixel_put(&par, i, j, 0x00000000);
			i++;
		}
		j++;
	}
}
