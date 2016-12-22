/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/19 17:07:29 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	min_map_size(t_list *lst)
{
	size_t	i;
	size_t	map_start_size;

	map_start_size = ft_lstsize(lst) * 4;
	i = 1;
	while ((i * i) < map_start_size)
		i++;
	return (i);
}

void	print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
}

char	**init_map(size_t size)
{
	char	**map;
	size_t	i;
	size_t	y;

	if (!(map = (char **)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = ft_strnew(size)))
		{
			delete_map(map);
			return (NULL);
		}
		y = 0;
		while (y < size)
			map[i][y++] = '.';
		i++;
	}
	return (map);
}

void	delete_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
