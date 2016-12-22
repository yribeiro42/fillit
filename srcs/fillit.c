/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/21 17:29:17 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char *filename)
{
	t_list	*lst;
	char	**map;
	size_t	size;

	if (!(lst = read_file(filename)))
		return (print_error());
	size = min_map_size(lst);
	map = init_map(size);
	while (!solve(map, lst, 'A', size))
	{
		size++;
		delete_map(map);
		map = init_map(size);
	}
	print_map(map);
	delete_map(map);
	ft_lstdel(&lst, &free_tetrimino_lst);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fillit(argv[1]);
	else
		print_usage();
	return (0);
}
