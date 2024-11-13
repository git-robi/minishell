/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:42:05 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 13:03:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"
#include <stdlib.h>

int	store_right_brackets(char *input, t_lexer **token_list)
{
	t_lexer *new_node;

	if (*(input + 1) == '>')
	{
		new_node = new_node_lexer(">>", HERE_DOC);
		if (new_node == NULL)
			return (-1);
		add_node_lexer(new_node, token_list);
		return (2);
	}
	new_node = new_node_lexer(">", REDIR_OUT);
	if (new_node == NULL)
		return (-1);
	add_node_lexer(new_node, token_list);
	return (1);
}

int	store_left_brackets(char *input, t_lexer **token_list)
{
	t_lexer *new_node;
	
	if (*(input + 1) == '<')
	{
		new_node = new_node_lexer("<<", APPEND);
		if (new_node == NULL)
			return (-1);
		add_node_lexer(new_node, token_list);
		return (2);
	}
	new_node = new_node_lexer("<", REDIR_IN);
	if (new_node == NULL)
		return (-1);
	add_node_lexer(new_node, token_list);
	return (1);
}

int	store_word(char *input, t_lexer **token_list)
{
	int	end;
	t_lexer	*new_node;

	end = 0;
	if (input[0] == '\'' || input[0] == '\"')
		return (store_token_in_quotes(input,  token_list));
	while (input[end])
	{
		if (input[end] == '<' || input[end] == '>' || input [end] == '|')
			break ;
		end++;
	}
	new_node = new_node_lexer(ft_substr(input, 0, end), WORD);
	if (new_node == NULL)
		return (-1);
	add_node_lexer(new_node, token_list);
	return (end);
}

int	store_token(char *input, t_mini *data)
{
	t_lexer	*new_node;

	if (*input == '<')
		return (store_left_brackets(input, &data->lexer));
	else if (*input == '>')
		return (store_right_brackets(input, &data->lexer));
	else if (*input == '|')
	{
		new_node = new_node_lexer("|", PIPE);
		if (new_node == NULL)
			return (-1);
		add_node_lexer(new_node, &data->lexer);
	}
	else
		return (store_word(input, &data->lexer));
	return (1);
}
