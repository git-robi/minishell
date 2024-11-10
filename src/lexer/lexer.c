/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 13:40:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c > 8 && c < 14)
		return (1);
	return (0);
}

int	read_token(t_mini *data)
{	
	int		i;
	int		j;

	i = 0;
	data->line = ft_strtrim(input, " ");
	while (data->line[i])
	{
		while (is_whitespace(data->line[i]))
			i++;
		j = store_token(&data->line[i], data);
		if (j < 0)
			free_data(data, EXIT_FAILURE);
		i = i + j;
	}
	return (0);
}
