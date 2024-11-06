/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:54:27 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/06 11:56:45 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/parser.h"
#include "../../includes/lexer.h"

int	error_check(t_mini *data)
{
	t_lexer	*node;

	node = data->lexer;
	if (node->type == PIPE)
		return (1); //check for correct error code
	node = node->next;
	while (node)
	{
		if (node->type == != WORD)
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

int	count_commands(t_mini *data)
{
	int	cmds_num;
	t_lexer	*tmp;

	cmds_num = 0;
	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		cmds_num++;
		tmp = tmp->next;
	}
	return (cmds_num);
}
