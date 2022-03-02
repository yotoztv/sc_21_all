/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koko.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:00:59 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:01:09 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void		my_mlx_pixel_put(t_par *par, int x, int y, int color)
{
	char	*dst;

	dst = par->addr + (y * par->line_length + x * (par->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_par		load_tx_2(t_par par)
{
	if (check_second_sp(par, '2') == 1)
		par.img_txb = mlx_xpm_file_to_image(par.mlx,
			par.rel_path_txb, &par.img_w_txb, &par.img_h_txb);
	if ((check_second_sp(par, '2') == 1) && !(par.img_txb))
		exit_program_img();
	if (check_second_sp(par, '2') == 1)
		par.ardr_txb = mlx_get_data_addr(par.img_txb,
			&par.bits_per_p_tx_b, &par.line_len_tx_b, &par.endian_txb);
	if (check_second_sp(par, '7') == 1)
		par.img_txf = mlx_xpm_file_to_image(par.mlx,
		par.rel_path_txf, &par.img_w_txf, &par.img_h_txf);
	if ((check_second_sp(par, '7') == 1) && !(par.img_txf))
		exit_program_img();
	if (check_second_sp(par, '7') == 1)
		par.ardr_txf = mlx_get_data_addr(par.img_txf,
		&par.bits_per_p_tx_f, &par.line_len_tx_f, &par.endian_txf);
	return (par);
}

t_par		load_tx_1(t_par par)
{
	par.img_tx1 = mlx_xpm_file_to_image(par.mlx,
		par.rel_path_tx1, &par.img_w_tx1, &par.img_h_tx1);
	par.img_tx2 = mlx_xpm_file_to_image(par.mlx,
		par.rel_path_tx2, &par.img_w_tx2, &par.img_h_tx2);
	par.img_tx3 = mlx_xpm_file_to_image(par.mlx,
		par.rel_path_tx3, &par.img_w_tx3, &par.img_h_tx3);
	par.img_tx4 = mlx_xpm_file_to_image(par.mlx,
		par.rel_path_tx4, &par.img_w_tx4, &par.img_h_tx4);
	if (!(par.img_tx1 && par.img_tx2 && par.img_tx3 && par.img_tx4))
		exit_program_img();
	par.ardr_tx1 = mlx_get_data_addr(par.img_tx1,
		&par.bits_per_p_tx_1, &par.line_len_tx_1, &par.endian_tx1);
	par.ardr_tx2 = mlx_get_data_addr(par.img_tx2,
		&par.bits_per_p_tx_2, &par.line_len_tx_2, &par.endian_tx2);
	par.ardr_tx3 = mlx_get_data_addr(par.img_tx3,
		&par.bits_per_p_tx_3, &par.line_len_tx_3, &par.endian_tx3);
	par.ardr_tx4 = mlx_get_data_addr(par.img_tx4,
		&par.bits_per_p_tx_4, &par.line_len_tx_4, &par.endian_tx4);
	return (par);
}

t_par		corect_rez(t_par par)
{
	mlx_get_screen_size(&par.mlx, &par.rez_grz_max, &par.rez_vrt_max);
	if (par.rez_grz > par.rez_grz_max)
	{
		par.rez_grz = par.rez_grz_max;
		ft_putstr_fd("Your horizontal rezolution changed\n", 1);
	}
	if (par.rez_vrt > par.rez_vrt_max)
	{
		par.rez_vrt = par.rez_vrt_max;
		ft_putstr_fd("Your vertical rezolution changed\n", 1);
	}
	if (par.rez_grz < 100)
	{
		par.rez_grz = 100;
		ft_putstr_fd("Your horizontal rezolution changed\n", 1);
	}
	if (par.rez_vrt < 100)
	{
		par.rez_vrt = 100;
		ft_putstr_fd("Your vertical rezolution changed\n", 1);
	}
	return (par);
}

t_par		to_go(t_par par)
{
	par.mlx = mlx_init();
	if (par.save_bmp == 0)
		par.win = mlx_new_window(par.mlx,
		par.rez_grz, par.rez_vrt, "dlucio's game");
	par.img = mlx_new_image(par.mlx, par.rez_grz, par.rez_vrt);
	par.addr = mlx_get_data_addr(par.img,
		&par.bits_per_pixel, &par.line_length, &par.endian);
	par = load_tx_1(par);
	par = load_tx_2(par);
	par = draw_3d(par);
	return (par);
}
