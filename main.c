/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:54:32 by marvin            #+#    #+#             */
/*   Updated: 2020/08/29 23:00:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd;
	int gnl;

	if (ac == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	/*if ((gnl = get_next_line(fd, &line)) != 0)
	{
		printf("%s", line);
		free(line);
	}*/
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		printf("gnl = %d ", gnl);
		printf("%s", line);
		free(line);
	}
	printf("gnl = %d ", gnl);
	printf("last -- %s", line);
	return (0);
}
