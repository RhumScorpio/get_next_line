/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2020/10/02 11:51:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!src)
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (*(src + i) != '\0' && i < n)
	{
		tmp[i] = src[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		line_copy(char **line, t_all *a)
{
	int	i;

	i = 0;
	if (!a->str)
	{
		*line = ft_strdup("");
		return (0);
	}
	while (a->str[i] && a->str[i] != '\n')
		i++;
	*line = ft_strndup(a->str, i);
	if (ft_strchr(a->str, '\n') == -1)
		return (0);
	return (i + 1);
}

static int		gnl_read(int fd, t_all *a, char **line)
{
	int		end;
	int		foo;
	int		i;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	i = 0;
	while ((end = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[end] = 0;
		tmp = a->str;
		a->str = ft_strjoin(a->str, buff);
		free(tmp);
		if ((i = ft_strchr(a->str, '\n')) >= 0)
			break ;
	}
	foo = line_copy(line, a);
	return (foo);
}

int				get_next_line(int fd, char **line)
{
	static t_all	all;
	int				end;
	char			*tmp;
	char			test[BUFFER_SIZE + 1];

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, test, 0) == -1)
		return (-1);
	end = gnl_read(fd, &all, line);
	tmp = all.str;
	if (tmp && end != 0 && tmp[end] != '\0')
	{
		all.str = ft_strdup(all.str + end);
		free(tmp);
	}
	else
	{
		all.str = NULL;
		free(tmp);
	}
	if (end == 0)
		return (0);
	return (1);
}
