/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 12:25:54 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser_simple_z_2(t_par *par)
{
	while (next_point_zap(par) != 0 && par->flag_psz == 1)
	{
		if ((par->str_next_zap[1]) == NULL)
			break ;
		if (is_pipe(par->str_next_zap[1]) == 1 ||
		is_point(par->str_next_zap[1]) ||
		is_riderects((par->str_next_zap[1]), par))
		{
			ft_putstr_fd("oil_shell: syntax error\n", 2);
			par->flag_psz = 7;
			break ;
		}
		else
		{
			parser_simple(par);
			par->str = par->str_next_zap + 1;
		}
	}
}

void	parser_simple_z(char *line, t_par *par)
{
	par->flag_psz = 1;
	par->str = copy_mtrx(parsing(line, par));
	ft_free_mtrx(par->str_na);
	if (check_in_sintax(par) == 1)
		par->flag_psz = 7;
	par->str_based = par->str;
	parser_simple_z_2(par);
	if (par->flag_psz != 7)
		parser_simple(par);
	ft_free_mtrx(par->str_based);
}
