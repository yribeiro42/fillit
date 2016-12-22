/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:04 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/19 19:15:34 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (!alst)
		return ;
	current = *alst;
	while (current)
	{
		next = current->next;
		del(current->content, current->content_size);
		free(current);
		current = next;
	}
	*alst = NULL;
}
