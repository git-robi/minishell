/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:55 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 12:46:03 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*void	clean_line(char **line)
{
	char	*tmp;
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == ' ')
		{
			(*line)[i] = (*line)[ft_strlen(*line) - 1];
			(*line)[ft_strlen(*line) - 1] = ' ';
			break;
		}
		i++;
	}
	tmp = ft_strtrim(*line, " ");
	free(*line);
	*line = tmp;
}*/
