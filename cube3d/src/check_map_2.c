/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:53:52 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 19:54:38 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	exit_program_zero(t_par par, char *mess)
{
	ft_putstr_fd(mess, 1);
	par.crossx = 0;
	ft_putstr_fd("I'm exit program\n", 1);
	exit(0);
}

t_par	find_start_map(t_par par)
{
	while (par.map[par.j8++])
	{
		par.i8 = 0;
		while (par.map[par.j8][par.i8])
		{
			if (par.map[par.j8][par.i8] == ' ')
				par.i8++;
			else if ((par.map[par.j8][par.i8]) == '1' ||
			(par.map[par.j8][par.i8]) == '0' || (par.map[par.j8][par.i8]) ==
			'7' || (par.map[par.j8][par.i8]) == '2')
			{
				par.xmap_start = par.i8;
				par.ymap_start = par.j8;
				return (par);
			}
			else
			{
				par.j8++;
				par.i8 = 0;
				continue;
			}
		}
	}
	exit_program_zero(par, "Error\nValid Map not found...\n");
	return (par);
}

t_par	init_i8_j8_k8_kik8(t_par par)
{
	par.i8 = 0;
	par.j8 = 0;
	par.k8 = 0;
	par.kik8 = 0;
	par.r_c = -1;
	par.g_c = -1;
	par.b_c = -1;
	ft_bzero(par.str_rezult, 99);
	return (par);
}
