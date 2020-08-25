/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:10 by clesaffr          #+#    #+#             */
/*   Updated: 2020/08/25 12:31:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	c;

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

	if (!s1 && s2)
		return (ft_strndup(s2, ft_strlen(s2)));
	if (s1 && !s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(p = (char *)malloc(size * sizeof(*p))))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		p[i] = s1[i];
	j = i - 1;
	i = -1;
	while (++i < n)
		p[j + i] = s2[i];
	p[j + i + 1] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (p);
}

int		ft_strrchr(const char *s, int c)
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

char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*tmp;

	i = 0;
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
