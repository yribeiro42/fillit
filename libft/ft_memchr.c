/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:52:03 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 10:50:44 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cp;

	cp = (unsigned char *)s;
	while (n--)
	{
		if (*cp == (unsigned char)c)
			return (cp);
		cp++;
	}
	return (NULL);
}
