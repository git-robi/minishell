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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	clean_line(char **line)
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
}
