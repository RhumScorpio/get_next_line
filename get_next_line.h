/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:14 by clesaffr          #+#    #+#             */
/*   Updated: 2020/08/25 11:56:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_all
{
	char buff[BUFFER_SIZE + 1];
	char *str;
}				t_all;

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
int				ft_strrchr(const char *s, int c);
char			*ft_strndup(const char *src, int n);
char			*ft_strnjoin(const char *s1, const char *s2, int n);

#endif
