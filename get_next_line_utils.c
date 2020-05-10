/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:10 by clesaffr          #+#    #+#             */
/*   Updated: 2020/03/12 18:02:22 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
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
	int		i;
	int		j;
	char		*p;
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

char	*ft_strdup(char *src)
{
	int	len;
	int	i;
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

