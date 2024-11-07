/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:32:56 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/15 17:23:24 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *ubi, size_t tam)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = ubi;
	while (i < tam)
	{
		p[i] = 0;
		i++;
	}
}
