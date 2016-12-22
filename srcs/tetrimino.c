/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/19 21:48:07 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	decaly(char **t)
{
	char *tmp;

	tmp = t[0];
	t[0] = t[1];
	t[1] = t[2];
	t[2] = t[3];
	t[3] = tmp;
}

void	decalx(char **t)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < T_HEIGHT)
	{
		tmp = t[i][0];
		t[i][0] = t[i][1];
		t[i][1] = t[i][2];
		t[i][2] = t[i][3];
		t[i][3] = tmp;
		i++;
	}
}

void	align_tetrimino(char **t)
{
	while (!ft_strcmp(*t, "...."))
		decaly(t);
	while (t[0][0] == '.' &&
			t[1][0] == '.' &&
			t[2][0] == '.' &&
			t[3][0] == '.')
		decalx(t);
}
