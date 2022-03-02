/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:57:14 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:57:28 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_par		init_pl(t_par par)
{
	par.s_id = 0;
	par.wall_nswe = 0;
	par.dplx = par.plx + 0.5;
	par.dply = par.ply + 0.5;
	par.st = 0.01;
	par.delta = 0;
	par.len = 0;
	par.erka = 0;
	par.crossx = par.dplx;
	par.crossy = par.dply;
	par.angle = 60;
	par.omega = (par.angle) * M_PI / 180;
	par.view = (par.rez_grz / 2) / tan(par.omega / 2);
	par.st_angle = par.angle / par.rez_grz;
	par.delta = par.angle / 2 * -1;
	par.ih = 0;
	return (par);
}

t_par		parser_pl(t_par par)
{
	int		j;
	int		i;

	j = 0;
	while (par.map[j])
	{
		i = 0;
		while (par.map[j][i])
		{
			if ((par.map[j][i]) == 'N' || (par.map[j][i]) == 'S' ||
				(par.map[j][i]) == 'W' || (par.map[j][i]) == 'E')
			{
				par.plx = i;
				par.ply = j;
				par.plsun = par.map[j][i];
				par.map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
	par = init_pl(par);
	par = parser_plsun(par);
	return (par);
}

t_par		parser_map(t_par par)
{
	par.longline = ft_strnew(1);
	while ((get_next_line(par.fd, &par.line)) > 0)
	{
		if (ft_strrchr(par.line, '%') != NULL)
			exit_program_zero(par,
				"Map's file included '%', (give me valid file)");
		par.longline = ft_strjoin_fr(par.longline, par.line);
		par.longline = ft_strjoin_fr(par.longline,
			"                         %                         ");
		free(par.line);
	}
	if (ft_strrchr(par.line, '%') != NULL)
		exit_program_zero(par,
			"Map's file included '%', (give me valid file)");
	par.longline = ft_strjoin_fr(par.longline, par.line);
	par.longline = ft_strjoin_fr(par.longline,
			"                         %                         ");
	if (ft_strrchr(par.line, '%') != NULL)
		exit_program_zero(par,
			"Map's file included '%%', (give me valid file)");
	par.map = ft_split(par.longline, '%');
	free(par.longline);
	free(par.line);
	par = check_valid_map(par);
	return (par);
}

int			main(int argc, char *argv[])
{
	t_par	par;

	par.save_bmp = 0;
	if (argc < 2)
		exit_program_zero(par, "Can't find *.cub file \n");
	if (argc >= 3 && (ft_strncmp(argv[2], "--save", 6)
		== 0) && ft_strlen(argv[2]) == 6)
		par.save_bmp = 1;
	ft_putstr_fd("Kuʻu One Hanau...\n", 1);
	if ((par.fd = open(argv[1], O_RDONLY)) < 0)
		exit_program_zero(par, "Can't load *.cub file \n");
	par = parser_map(par);
	par = to_go(par);
	return (0);
}
