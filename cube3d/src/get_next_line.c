/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:00:14 by dlucio            #+#    #+#             */
/*   Updated: 2020/10/26 20:00:22 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int				root_n(char *root)
{
	int			i;

	i = 0;
	if (!root)
		return (i);
	while (root[i])
	{
		if (root[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char			*save_line(char *root)
{
	int			len;
	char		*line;

	len = 0;
	if (!root)
		return (0);
	while (root[len] != '\0' && root[len] != '\n')
		len++;
	if (!(line = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (root[len] != '\0' && root[len] != '\n')
	{
		line[len] = root[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char			*save_root(char *root)
{
	char		*new;
	int			del;
	int			i;

	del = 0;
	i = 0;
	if (!root)
		return (0);
	while (root[del] != '\0' && root[del] != '\n')
		del++;
	if (!root[del])
	{
		free(root);
		return (0);
	}
	if (!(new = malloc(sizeof(char) * ((ft_strlen_ch(root) - del) + 1))))
		return (0);
	del++;
	while (root[del])
		new[i++] = root[del++];
	new[i] = '\0';
	free(root);
	return (new);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*root;
	int			i;

	i = 1;
	if ((fd < 0 || !line || 10 <= 0) ||
		(!(buf = malloc(sizeof(char) * (10 + 1)))))
		return (-1);
	while (!root_n(root) && i != 0)
	{
		if ((i = read(fd, buf, 10)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		if (!((root = ft_strjoin_fr(root, buf))))
			return (0);
	}
	free(buf);
	if (!((*line = save_line(root))))
		return (-1);
	root = save_root(root);
	return (i == 0) ? 0 : 1;
}
