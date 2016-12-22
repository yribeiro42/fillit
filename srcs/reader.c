/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/21 17:23:43 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_line(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		i;

	if (fd < 0 || read(fd, buff, BUFF_SIZE + 1) != BUFF_SIZE + 1)
		return (NULL);
	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buff[i] != '.' && buff[i] != '#')
			return (NULL);
		i++;
	}
	if (buff[BUFF_SIZE] != '\n')
		return (NULL);
	return (ft_strsub(buff, 0, BUFF_SIZE));
}

int		next_tetrimino(int fd)
{
	char	buff[1];

	if (fd < 0 || read(fd, buff, 1) == -1 || !*buff)
		return (0);
	if (*buff == '\n')
		return (1);
	else
		return (-1);
}

char	**read_tetrimino(int fd)
{
	int		i;
	char	**tetrimino;

	i = 0;
	if (!(tetrimino = (char **)ft_memalloc(sizeof(char *) * (T_HEIGHT + 1))))
		return (NULL);
	while (i < T_HEIGHT)
	{
		if (!(tetrimino[i] = read_line(fd)))
		{
			free_tetrimino(tetrimino);
			free(tetrimino);
			return (NULL);
		}
		i++;
	}
	return (tetrimino);
}

t_list	*read_file(char *filename)
{
	t_list	*lst;
	int		fd;
	char	**tetrimino;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	lst = NULL;
	while (1)
	{
		if (!(tetrimino = read_tetrimino(fd)))
			return (NULL);
		if (check_tetrimino(tetrimino))
		{
			align_tetrimino(tetrimino);
			ft_lstaddend(&lst, ft_lstnew(tetrimino, sizeof(tetrimino) * 4));
		}
		else
		{
			ft_lstdel(&lst, &free_tetrimino_lst);
			return (NULL);
		}
		if (!next_tetrimino(fd))
			break ;
	}
	return (lst);
}
