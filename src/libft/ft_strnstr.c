/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:55:39 by aprenafe          #+#    #+#             */
/*   Updated: 2024/11/19 23:13:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] != '\0')
	{
		while (i < len && haystack[i])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				if (needle[j + 1] == '\0')
				{
					return ((char *)&haystack[i]);
				}
				j++;
			}
			j = 0;
			i++;
		}
		return (NULL);
	}
	return ((char *)&haystack[i]);
}
