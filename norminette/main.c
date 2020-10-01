/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:58:52 by marvin            #+#    #+#             */
/*   Updated: 2020/09/30 10:59:32 by marvin           ###   ########.fr       */
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

	if(!(fd =  open(av[1], O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("NORM ! %s", line);
		free(line);
	}
	printf("LAST ! %s", line);
	printf("gnl = %d", gnl);
	return (0);

}
