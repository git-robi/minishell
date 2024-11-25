/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:41:17 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 13:37:06 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*punt;
	char	letra;

	i = 0;
	if (s && f)
	{
		j = ft_strlen((char *)s);
		punt = malloc((j + 1) * sizeof(char));
		if (!punt)
			return (0);
		while (i < j)
		{
			letra = s[i];
			punt[i] = f(i, letra);
			i++;
		}
		punt[i] = '\0';
		return (punt);
	}
	else
		return (NULL);
}
