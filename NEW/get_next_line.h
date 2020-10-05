/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 00:04:42 by marvin            #+#    #+#             */
/*   Updated: 2020/10/01 16:32:04 by marvin           ###   ########.fr       */
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
	char *str;
}				t_all;

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s1);

#endif
