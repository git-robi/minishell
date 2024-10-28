/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:42:05 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 14:05:25 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	store_right_brackets(char *input, t_lexer **token_list)
{
	t_lexer *new_node;

	if (*(input + 1) == '<')
	{
		new_node = new_node_lexer("<<", APPEND, token_list); //add check for malloc fail
		//add node to the list
		return (2);
	}
	new_node = new_node_lexer("<", REDIR_IN, token_list); //add check for malloc fail
	return (1);
}

int	store_left_brackets(char *input, t_lexer **token_list)
{
	t_lexer *new_node;
	
	if (*(input + 1) == '<')
	{
		new_node = new_node_lexer("<<", APPEND, token_list); //add check for malloc fail
		//add node to the list
		return (2);
	}
	new_node = new_node_lexer("<", REDIR_IN, token_list); //add check for malloc fail
	return (1);
}

int	store_word(char *input, t_lexer **token_list)
{
	int	i;
	t_lexer	*new_node;

	i = 0;
	while (input[i])
	{
		//add some quotes handling
		if (input[i] == '<' || input[i] == '>' || input [i] == '|')
			break ;
		i++
	}
	new_node = new_node_lexer(ft_substr(input, 0, i), WORD, token_list); //add check for malloc fail
	//add node to list
	return (i);
}

int	store_token(char *input, t_lexer **token_list)
{
	t_lexer	*new_node;

	if (*input == '<')
		return (store_left_brackets(input, token_list));
	else if (*input == '>')
		return (store_right_brackets(input, token_list));
	else if (*input == '|')
	{
		new_node = new_node_lexer("|", PIPE, token_list);
		//add node to list
	}
	else
		return (store_word(input, token_list);
	return (1);
}
