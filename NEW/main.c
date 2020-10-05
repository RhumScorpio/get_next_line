/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:58:52 by marvin            #+#    #+#             */
/*   Updated: 2020/10/01 19:46:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int fd;
	int gnl;
	char *line = NULL;

	if (ac == 0)
		return (0);
	//TEST 1>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(!(fd =  open(av[1], O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((gnl = get_next_line(fd, NULL)) > 0)
	{
		printf("NORM ! %s\n", line);
		free(line);
	}
	printf("LAST ! %s\n", line);
	printf("gnl = %d\n_______\n_______\n", gnl);
	close(fd);
	return(0);
}
