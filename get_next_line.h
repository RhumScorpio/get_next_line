/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:14 by clesaffr          #+#    #+#             */
/*   Updated: 2020/03/12 17:55:09 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_POINT_H
# define FT_POINT_H

 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>

typedef	struct	s_all
{
	char buff[BUFFER_SIZE + 1];
	int boolean;
}				t_all;

int     get_next_line(int fd, char **line);

#endif
