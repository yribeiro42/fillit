/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/21 20:53:07 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 4
# define T_HEIGHT 4

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_list			*read_file(char *filename);
void			free_tetrimino(char **t);
void			free_tetrimino_lst(void *t, size_t size);

void			align_tetrimino(char **t);
int				check_tetrimino(char **t);

size_t			min_map_size(t_list *lst);
void			print_map(char **map);
char			**init_map(size_t size);
void			delete_map(char **map);

void			print_error(void);
void			print_usage(void);

int				solve(char **map, t_list *lst, char num, size_t size);

#endif
