/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:47:35 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 13:17:16 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*punt;

	i = 0;
	punt = s;
	while (i < n)
	{
		if (punt[i] == (unsigned char)c)
			return ((void *)&punt[i]);
		i++;
	}
	return (0);
}
