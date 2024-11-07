/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:20:50 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/15 16:56:09 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = malloc(i + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s1[j] != '\0')
	{
		dup[j] = s1[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
