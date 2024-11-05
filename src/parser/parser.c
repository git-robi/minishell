/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:22 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/05 15:08:56 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/lexer.h"

int	pipes_error_check(t_mini *data)
{
	t_lexer	*node;

	node = data->lexer;
	if (node->type == PIPE)
		return (1); //check for correct error code
	node = node->next;
	while (node)
	{
		if (node->type == PIPE)
		{
			if (node->next == NULL)
				return (1);
			else if (node->prev.type != WORD || node->next.type != WORD)
				return (1);
		}
		node = node->next;
	}
	return (0);
}

int	parser(t_mini *data)
{
	if (pipes_error_check(data))
		return (code);
}
	
