/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:51:06 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 14:54:05 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	add_node_lexer(t_list *new_node, t_lexer **token_list)
{
	t_lexer	*temp_node;

	temp_node = *token_list;
	if (*token_list == NULL)
	{
		*token_list = new_node;
		return ;
	}
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	temp_node->next = new_node;
	new_node->prev = temp_node;
}

t_lexer	*new_node_lexer(char *str, int type, t_lexer **token_list)
{
	t_lexer		*new_node;
	static	int	idx = 0;
	
	new_node = (t_lexer *)malloc(sizeof(t_lexer) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->token = str;
	new_node->type = type;
	new_node->idx = idx;
	idx++;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
