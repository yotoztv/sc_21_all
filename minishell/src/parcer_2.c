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

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

char	*ft_strjoin_mod_free(char *s1, char s2)
{
	char *tmp;

	tmp = s1;
	s1 = ft_strjoin_mod(s1, s2);
	free(tmp);
	return (s1);
}

char	*ft_strjoin_mod(char *s1, char c)
{
	char	*news;
	size_t	len_s1;
	size_t	i;
	size_t	j;

	if (!s1 || !c)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (!(news = ft_calloc(sizeof(char), (len_s1 + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_s1 + 1)
	{
		if (i < len_s1)
			news[i] = s1[i];
		else
			news[i] = c;
		i++;
	}
	news[i] = '\0';
	return (news);
}

void	new_line(t_par *par, int *j)
{
	*j = *j + 1;
	par->str_na[*j] = malloc(sizeof(char) * 1);
	par->str_na[*j][0] = '\0';
}

int		check_no_quotes(char c)
{
	if (c != 39 && c != 34 && c != ' ' \
	&& c != '\0')
		return (1);
	return (0);
}
