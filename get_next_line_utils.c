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

char    *ft_strjoin(t_all *all)
{
        int                             i;
        char                    *p;

        all->size += all->ret;
	printf("A\n");
        if (!(p = (char *)malloc((all->size + 1) * sizeof(*p))))
                return (NULL);
	printf("B\n");
	i = 0;
        while (all->mark < all->size)
	{
                p[all->mark] = all->str[i];
		i++;
		all->mark++;
	}
        p[i] = '\0';
	printf("C\n");
	printf("p --- %s\n", p);
        return (p);
}
