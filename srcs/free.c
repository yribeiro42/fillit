/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/19 19:15:00 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetrimino(char **t)
{
	int i;

	i = 0;
	while (i < T_HEIGHT)
		free(t[i++]);
}

void	free_tetrimino_lst(void *t, size_t size)
{
	if (size > 0)
		free_tetrimino(t);
}
