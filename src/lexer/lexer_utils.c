/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:50:19 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/27 15:53:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int	there_is_space(char *line, int start, int end)
{
	while (line[end] == ' ')
		end--;
	while (end > start)
	{
		if (line[end] == ' ')
			return (1);
		end--;
	}
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	return (0);
}

