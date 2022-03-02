/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:02:17 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:02:24 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static int			get_sr_color(t_par *par, int x, int y)
{
	char			*dst;

	dst = par->addr + (y * par->line_length + x * (par->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void			header(unsigned char *header_arr,
	int size, t_par *par, int temp)
{
	header_arr[0] = (unsigned char)'B';
	header_arr[1] = (unsigned char)'M';
	header_arr[2] = (unsigned char)size;
	header_arr[3] = (unsigned char)(size >> 8);
	header_arr[4] = (unsigned char)(size >> 16);
	header_arr[5] = (unsigned char)(size >> 24);
	header_arr[10] = (unsigned char)54;
	header_arr[14] = (unsigned char)40;
	header_arr[18] = (unsigned char)temp;
	header_arr[19] = (unsigned char)(temp >> 8);
	header_arr[20] = (unsigned char)(temp >> 16);
	header_arr[21] = (unsigned char)(temp >> 24);
	header_arr[22] = (unsigned char)par->rez_vrt;
	header_arr[23] = (unsigned char)(par->rez_vrt >> 8);
	header_arr[24] = (unsigned char)(par->rez_vrt >> 16);
	header_arr[25] = (unsigned char)(par->rez_vrt >> 24);
	header_arr[26] = (unsigned char)1;
	header_arr[28] = (unsigned char)24;
}

static void			screen(t_par *par, int fd, int res)
{
	int				color;
	int				x;
	int				y;
	int				size_x;

	color = 0;
	x = 0;
	y = par->rez_vrt - 1;
	size_x = res;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = get_sr_color(par, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

int					screen_to_bmp(t_par *par)
{
	int				fd;
	unsigned char	header_arr[54];
	int				count;
	int				size;
	int				temp_res;

	temp_res = par->rez_grz;
	if (par->rez_grz % 4)
		temp_res = par->rez_grz - (par->rez_grz % 4);
	size = temp_res * par->rez_vrt + 54;
	count = 0;
	if ((fd = open("./preview.bmp", O_RDWR | O_CREAT, 0666)) < 0)
		return (-1);
	while (count < 54)
	{
		header_arr[count] = (unsigned char)0;
		count++;
	}
	header(header_arr, size, par, temp_res);
	write(fd, header_arr, 54);
	screen(par, fd, temp_res);
	close(fd);
	exit(0);
}
