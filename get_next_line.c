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
	printf("1\n");
	i = 0;
	all.mark = 0;
	while ((all.ret = read(fd, all.str, BUFFER_SIZE)) != -1)
	{
		while (i < BUFFER_SIZE && *(all.str + i) != '\n')
		{
			i++;
		}
		all.i = i;
		printf("2\n");
		*line = ft_strjoin(&all);
		printf("2.5\n");
		if (all.ret == 0 || all.i == BUFFER_SIZE + 1)
			all.ret = read(fd, all.str, BUFFER_SIZE);
		if (all.ret == 0)
			return (0);
		printf("3\n");
	}
	return (1);
}
