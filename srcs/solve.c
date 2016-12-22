/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/21 17:23:32 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*tmp_point(size_t indice, size_t size)
{
	t_point *point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		exit(1);
	point->x = (int)(indice / size);
	point->y = (int)(indice % size);
	return (point);
}

int			check(char **map, char **tetri, size_t size, t_point *point)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
			{
				if (point->x + i >= size || point->y + j >= size ||
					map[point->x + i][point->y + j] != '.')
				{
					free(point);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	free(point);
	return (1);
}

void		modify(char **map, char **tetri, char num, t_point *point)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] == '#')
				map[point->x + i][point->y + j] = num;
			j++;
		}
		i++;
	}
	free(point);
}

void		erase(char **map, char **tetri, t_point *point)
{
	modify(map, tetri, '.', point);
}

int			solve(char **map, t_list *lst, char num, size_t size)
{
	size_t	indice;

	if (!lst)
		return (1);
	indice = 0;
	while (indice < size * size)
	{
		if (check(map, (char **)lst->content, size, tmp_point(indice, size)))
		{
			modify(map, (char **)lst->content, num, tmp_point(indice, size));
			if (solve(map, lst->next, num + 1, size))
				return (1);
			else
				erase(map, (char **)lst->content, tmp_point(indice, size));
		}
		indice++;
	}
	return (0);
}
