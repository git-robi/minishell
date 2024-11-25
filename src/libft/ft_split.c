/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:28:02 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 15:13:27 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

static size_t	ft_wordsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_memorymaker(char **str, char *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = ft_wordsize(&s[i], c);
			str[j] = ft_substr(&s[i], 0, len);
			if (str[j] == NULL)
			{
				ft_free(str);
				return (NULL);
			}
			i += len;
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	words = malloc(sizeof(char *) * (ft_wordcounter(s, c) + 1));
	if (!words || !s)
		return (NULL);
	return (ft_memorymaker(words, (char *)s, c));
}
