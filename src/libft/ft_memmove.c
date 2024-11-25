/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:27:14 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 14:15:55 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*destino;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	destino = (char *)dst;
	source = (const char *)src;
	if (destino > source)
	{
		i = len;
		while (i--)
			destino[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destino[i] = source[i];
			i++;
		}
	}
	return (dst);
}
