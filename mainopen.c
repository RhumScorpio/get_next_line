/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:26:24 by clesaffr          #+#    #+#             */
/*   Updated: 2020/03/12 17:46:11 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int main(int ac, char **av)
  {
  ssize_t num;

  int a;
  int b;
  int c_num;

  c_num = 10;
  b = c_num;
  a = c_num + 1;

  int fd;
  char s[a];

  fd = open(av[1], O_RDONLY);
  printf("FD --- %d\n", fd);
  if (fd == -1)
  {
  write(2, "open error\n", 11);
  return (0);
  }

  num = read(fd, s, c_num);
  s[b] = '\0';
//ft_putstr(s);
printf("%s\n", s);
printf("%zd\n", num);
read(fd, s, c_num);
printf("%s", s);

//	system("leaks a.out");
return(0);
}*/

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
	return (0);
}
