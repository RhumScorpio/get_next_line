/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/09/02 20:03:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		line_copy(char **line, char *content, char c)
{
	int	i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

static	int		gnl_read(int fd, char *str)
{
	int	end;
	int	i;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	i = 0;
	while ((end = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[end] = 0;
		tmp = all->str;
		all->str = ft_strfjoin1(all->str, buff);
		free(tmp);
		if ((i = ft_strrchr(tmp, '\n')) >= 0)
			break;
	}
	return (end);
}

int		get_next_line(int fd, char **line)
{
	static t_all	*all;
	int		end;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, all->buff, 0) == -1)
		return (-1);
	end = gnl_read(fd, all->str);
	if (!all->str && end == 0)
		return (0);
	end = line_copy(line, all->str, '\n');
	tmp = all->str;
	if (tmp[end] != '\0')
	{
		all->str = ft_strdup(all->str + end + 1);
	}
	else
		tmp[0] = '\0';
	return (1);
}

