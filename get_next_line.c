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

int	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (*(str + c) != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strnjoin(const char *s1, const char *s2, int n)
{
	int				i;
	int				j;
	char			*p;
	unsigned int	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + n + 1;
	if (!(p = (char *)malloc(size * sizeof(*p))))
		return (NULL);
	i = -1;
	while (i++ < ft_strlen(s1))
		p[i] = s1[i];
	j = i - 1;
	i = -1;
	while (i++ < n)
		p[j + i] = s2[i];
	p[j + i + 1] = '\0';
	return (p);
}

int		ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	while (*(src + len) != '\0')
		++len;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (*(src + i) != '\0')
	{
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

void	filling_buff(t_all *all, char *str)
{
	int i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		all->buff[i] = str[i];
		i++;
	}
}

int	gnl_read(int fd, t_all *all, char **line)
{
	char *str;
	int end;
	int i;

	end = 0;
	i = 0;
	*line = ft_strdup("");
	while((end = read(fd, str, BUFFER_SIZE)) != -1)
	{
		if (i = ft_strrchr(str, '\n') >= 0)
		{
			if (*line)
				*line = ft_strnjoin(*line, str, i);
			all->buff = str + i + 1;
			return (1);
		}
		else

	}
}

int	get_next_line(int fd, char **line)
{
	int i;
	static t_all    all;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, all.str, 0) == -1)
		return (-1);
	gnl_read(fd, &all, &(*line));
	return (1);
}
