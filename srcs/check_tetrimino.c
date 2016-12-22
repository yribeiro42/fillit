/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/21 17:23:37 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetrimino_count(char **t)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count == 4);
}

int		check_tetrimino_links(char **t)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t[i][j] == '#')
			{
				if ((i == 3 || t[i + 1][j] != '#') &&
					(j == 3 || t[i][j + 1] != '#') &&
					(i == 0 || t[i - 1][j] != '#') &&
					(j == 0 || t[i][j - 1] != '#'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_tetrimino_links_count(char **t)
{
	int i;
	int c;

	i = 0;
	while (i < 16)
	{
		if (t[i / 4][i % 4] == '#' && !(c = 0))
		{
			if ((i / 4) < 3 && t[(i / 4) + 1][i % 4] == '#')
				c++;
			if ((i % 4) < 3 && t[i / 4][(i % 4) + 1] == '#')
				c++;
			if ((i / 4) > 0 && t[(i / 4) - 1][i % 4] == '#')
				c++;
			if ((i % 4) > 0 && t[i / 4][(i % 4) - 1] == '#')
				c++;
			if (c > 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_tetrimino(char **t)
{
	return (check_tetrimino_count(t) &&
			check_tetrimino_links(t) &&
			check_tetrimino_links_count(t));
}
