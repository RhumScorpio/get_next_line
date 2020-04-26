/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/03/12 18:02:19 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int i;
	static t_all    all;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, all.str, 0) == -1)
		return (-1);
	check_buffer();
	all.boolean = 1;
	gnl_read(fd, *all);
	return (1);
}

int	gnl_read(int fd, t_all *all)
{
	int i;

	i = 0;
	if (all->boolean == 0)
		return (0);
	else
	{
		if ((all->ret = read(fd, all->buff, BUFFER_SIZE)) != -1)
			return(-1);
		while (i < BUFFER_SIZE && *(all->buff + i) != '\n')
			i++;
		if (i == BUFFER_SIZE)
		{
			filling_str(i, all);
			gnl_read(fd, all);

		}
		else
		{
			filling_str(i, all);
			all->boolean = 0;
		}
	}
}

void	filling_str(int index, t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->str != '\0')
	{
		i++;
	}
	j = 0;
	while (j < index)
	{
		
	}
}
