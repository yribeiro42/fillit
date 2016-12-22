/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgeti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:36:43 by cblesche          #+#    #+#             */
/*   Updated: 2016/12/02 13:36:46 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstgeti(t_list *lst, size_t i)
{
	if (!lst || ft_lstsize(lst) <= i)
		return (NULL);
	while (i--)
		lst = lst->next;
	return (lst);
}
