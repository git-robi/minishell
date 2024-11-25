/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:35:45 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 13:35:14 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	longi;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	longi = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((longi + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < longi)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = '\0';
	return (str);
}
