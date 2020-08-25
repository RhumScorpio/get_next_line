/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/06/04 12:45:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	filling_buff(t_urfd *all, int index)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(all->buff))
	{
		all->str[i] = all->buff[index + 1 + i];
		i++;
	}
	all->str[i] = '\0';
}

static	int		checkstr(int fd, t_urfd *all)
{
	int	end;

	end = 0;
	if (all->str[0] != '\0')
	{
		while (end <= ft_strlen(all->str))
		{
			all->buff[end] = all->str[end];
			end++;
		}
		all->buff[end] = '\0';
		all->str[0] = '\0';
		return (1);
	}
	end = read(fd, all->buff, BUFFER_SIZE);
	all->buff[end] = '\0';
	return (end);
}

static	int		gnl_read(int fd, t_urfd *all, char **line)
{
	int	i;
	int	end;

	i = 0;
	*line = ft_strdup("");
	while ((end = checkstr(fd, all)) != -1)
	{
		if (all->buff[0] == '\0' && all->str[0] == '\0')
			return (0);
		if ((i = ft_strrchr(all->buff, '\n')) >= 0)
		{
			*line = ft_strnjoin(*line, all->buff, i);
			filling_buff(all, i);
			return (1);
		}
		*line = ft_strnjoin(*line, all->buff, ft_strlen(all->buff));
	}
	return (-1);
}

static	t_urfd	kifkiffd(int fd, urfd *thatfd)
{
	t_urfd *tmp;

	tmp = malloc(sizeof(t_urfd));
	while (thatfd)
	{
		if (fd == thatfd->fd)
		{
			return (thatfd);
		}
		thatfd = thatfd->nextfd;
	}
	tmp->fd = fd;
	tmp->buff = "new";
	thatfd->nextfd = tmp;
	return (thatfd);

}

int		get_next_line(int fd, char **line)
{
	static t_urfd	*urfd;
	t_urfd	*firstfd;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, all.buff, 0) == -1)
		return (-1);
	firstfd = malloc(sizeof(t_urfd));
	firstfd->next = NULL;
	urfd = kifkiffd(fd, firstfd);
	return (gnl_read(fd, urfd, &(*line)));
}
