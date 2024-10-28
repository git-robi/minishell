/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 11:59:21 by rgiambon         ###   ########.fr       */
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

int	store_token(char *input, t_lexer **token_list)
{
}

t_lexer	read_token(char *input)
{	
	t_lexer	*token_list;
	int		i;

	token_list = NULL;
	i = 0;
	//remove leading and trailing white spaces
	input = ft_strtrim(input, " ");
	while (input[i])
	{
		while (is_whitespace(input[i]))
			i++;
		i = i + store_token(&input[i], &token_list);
	}
}
		
		
		
	

}
