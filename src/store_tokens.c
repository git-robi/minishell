/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:42:05 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 13:48:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	store_right_brackets(char *input, t_lexer **token_list)
{
	if (*(input + 1) == '<')
	{
		create_new_node_lexer("<<", APPEND, token_list);
		//add node to the list
		return (2);
	}
	create_new_node_lexer("<", REDIR_IN, token_list);
	return (1);
}

int	store_left_brackets(char *input, t_lexer **token_list)
{
	if (*(input + 1) == '<')
	{
		create_new_node_lexer("<<", APPEND, token_list);
		//add node to the list
		return (2);
	}
	create_new_node_lexer("<", REDIR_IN, token_list);
	return (1);
}

int	store_word(char *input, t_lexer **token_list)
{
	int	i;

	i = 0;
	while (input[i])
	{
		//add some quotes handling
		if (input[i] == '<' || input[i] == '>' || input [i] == '|')
			break ;
		i++
	}
	create_new_node_lexer(ft_substr(input, 0, i), WORD, token_list);
	//add node to list
	return (i);
}

int	store_token(char *input, t_lexer **token_list)
{
	if (*input == '<')
		return (store_left_brackets(input, token_list));
	else if (*input == '>')
		return (store_right_brackets(input, token_list));
	else if (*input == '|')
	{
		create_new_node_lexer("|", PIPE, token_list);
		//add node to list
	}
	else
		return (store_word(input, token_list);
	return (1);
}
