/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/09/21 13:37:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		line_copy(char **line, t_all *a)
{
	int	i;

	i = 0;
	while (a->str[i] && a->str[i] != '\n')
		i++;
	*line = ft_strndup(a->str, i + 1);
	return (i);
}

static int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static	int		gnl_read(int fd, t_all *a)
{
	int	end;
	int	i;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	i = 0;
	while ((end = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[end] = 0;
		tmp = a->str;
		a->str = ft_strjoin(a->str, buff);
		free(tmp);
		if ((i = ft_strchr(a->str, '\n')) >= 1)
			break;
	}
	return (end);
}

int		get_next_line(int fd, char **line)
{
	static t_all	all;
	int		yn;
	int		end;
	char	*tmp;
	char	test[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, test, 0) == -1)
		return (-1);
	yn = gnl_read(fd, &all);
	if (yn == 0 && !all.str)
		return (0);	
	end = 1 + line_copy(line, &all);
	tmp = all.str;
	if (tmp[end] != '\0')
	{
		all.str = ft_strdup(all.str + end);
		free(tmp);
	}
	else
	{
		all.str = NULL;
		free(tmp);
	}
	return (1);
}
