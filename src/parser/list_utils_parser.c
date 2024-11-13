/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:18:39 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 16:01:05 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	free_node_parser(t_parser **node)
{
	if ((*node)->commands != NULL)
		free_strarr((*node)->commands);
	if ((*node)->redirections != NULL)
		free_lexer_list(&(*node)->redirections);
	free(*node);
	*node = NULL;
}

t_parser	*new_node_parser(void)
{
	t_parser	*new_node;

	new_node = malloc(sizeof(t_parser));
	if (new_node == NULL)
		return (NULL);
	new_node->commands = NULL;
	new_node->redirections = NULL;
	//add builtin function
	//consider to add n of redirections
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_parser(t_parser *new_node, t_parser **parser_list)
{
	t_parser	*temp_node;

	temp_node = *parser_list;
	if (*parser_list == NULL)
	{
		*parser_list = new_node;
		return ;
	}
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	temp_node->next = new_node;
	new_node->prev = temp_node;
}
