/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzoom <dzoom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:41 by dzoom             #+#    #+#             */
/*   Updated: 2021/03/22 17:02:49 by dzoom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_point(char *str)
{
	if (str == 0)
		return (0);
	if ((ft_memcmp("&z28!-;", str, (1 + ft_strlen("&z28!-;"))) == 0))
		return (1);
	return (0);
}

int	is_pipe(char *str)
{
	if (str == 0)
		return (0);
	if ((ft_memcmp("&z28!-|", str, (1 + ft_strlen("&z28!-|"))) == 0))
		return (1);
	return (0);
}

int	is_riderects(char *str, t_par *par)
{
	if (str == 0)
		return (0);
	if ((ft_memcmp("&z28!->", str, (1 + ft_strlen("&z28!->"))) == 0))
		par->rid_type = 1;
	else if ((ft_memcmp("&z28!->>", str, (1 + ft_strlen("&z28!->>"))) == 0))
		par->rid_type = 2;
	else if ((ft_memcmp("&z28!-<", str, (1 + ft_strlen("&z28!-<"))) == 0))
		par->rid_type = 3;
	else
	{
		par->rid_type = 0;
		return (0);
	}
	return (1);
}
