/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 13:37:23 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

//a function that takes the input line and returns a linked list with a token in each node.

int	is_whitespace(char c)
{
	if (c == ' ' || c > 8 && c < 14)
		return (1);
	return (0);
}

int	store_right_brackets(char *input, t_lexer **token_list)
{
	if (*(input + 1) == '<')
	{
		create_new_node_token("<<", APPEND, token_list);
		//add node to the list
		return (2);
	}
	create_new_node_token("<", REDIR_IN, token_list);
	return (1);
}

int	store_left_brackets(char *input, t_lexer **token_list)
{
	if (*(input + 1) == '<')
	{
		create_new_node_token("<<", APPEND, token_list);
		//add node to the list
		return (2);
	}
	create_new_node_token("<", REDIR_IN, token_list);
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
	create_new_node_token(ft_substr(input, 0, i), WORD, token_list);
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
		create_new_node_token("|", PIPE, token_list);
		//add node to list
	}
	else
		return (store_word(input, token_list);
	return (1);
}

t_lexer	read_token(char *input)
{	
	t_lexer	*token_list;
	int		i;

	token_list = NULL;
	i = 0;
	//remove leading and trailing white spaces:
	input = ft_strtrim(input, " ");
	while (input[i])
	{
		while (is_whitespace(input[i]))
			i++;
		i = i + store_token(&input[i], &token_list);
	}
}
