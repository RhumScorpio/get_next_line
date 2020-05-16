/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:26:24 by clesaffr          #+#    #+#             */
/*   Updated: 2020/05/14 18:28:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int gnl;
	char *line = NULL;
	int fd;

	if (ac == 0)
		return (0);
	printf("ok\n");
	fd = open(av[1], O_RDONLY);
	printf("fd is ok\n");
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	gnl = get_next_line(fd, &line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	free(line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	printf("FINAL_________gnl = %d\nFINAL____line --- %s\n", gnl, line);
	return (0);
}
