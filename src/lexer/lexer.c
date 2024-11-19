/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/13 11:20:57 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"
#include <stdio.h>

int	is_whitespace(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	return (0);
}

void	read_token(t_mini *data)
{	
	int		i;
	int		j;
	char		*str;
	i = 0;

	str = ft_strtrim(data->line, " ");
	free(data->line);
	data->line = str;
	while (data->line[i])
	{
		while (is_whitespace(data->line[i]))
			i++;
		j = store_token(&data->line[i], data);
		if (j < 0)
			free_data_and_exit(data, EXIT_FAILURE);
		i = i + j;
	}
}
