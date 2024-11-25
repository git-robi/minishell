/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:47:57 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 13:46:23 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count > 0 && count * size / count != size)
		return (0);
	memory = malloc(size * count);
	if (memory == 0)
		return (0);
	ft_bzero(memory, (size * count));
	return (memory);
}
