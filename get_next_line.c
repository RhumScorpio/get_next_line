/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/08/25 12:27:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_read(int fd, t_all *all, char **line)
{
	int	end;
	int	i;
	char	*tmp;

	i = 0;
	tmp = strndup("", 1);
	while ((end = read(fd, all->buff, BUFFER_SIZE)) > 0)
	{
		all->buff[end] = 0;
		tmp = ft_strnjoin(tmp, all->buff, ft_strlen(all->buff));
		if ((i = ft_strrchr(tmp, '\n')) >= 0)
			break;
	}
	if (end == 0 && !all->str)
		return (0);
	*line = ft_strndup(tmp, i + 1);
	all->str = ft_strndup(tmp + i + 1, ft_strlen(tmp));
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_all	all;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, all.buff, 0) == -1)
		return (-1);
	return (gnl_read(fd, &all, &(*line)));
}

