/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 05:25:47 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/20 05:25:50 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(news = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			news[i] = s1[i];
		else
			news[i] = s2[j++];
		i++;
	}
	news[i] = '\0';
	return (news);
}
