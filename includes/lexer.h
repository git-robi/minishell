/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:12:51 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 13:47:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#define	WORD		1
#define	PIPE		2
#define	REDIR_IN	3
#define	REDIR_OUT	4
#define	APPEND		5
#define	HERE_DOC	6
#define	END			0

typedef struct s_lexer
{
	char	*token;
	int		type;
	//maybe add index (?)
	t_lexer	*next;
	t_lexer	*prev;
}	t_lexer;

t_lexer read_token(char *input);
int 	is_whitespace(char c);
int 	store_token(char *input, t_lexer **token_list);
int		store_word(char *input, t_lexer **token_list);
int 	store_left_brackets(char *input, t_lexer **token_list);
int 	store_right_brackets(char *input, t_lexer **token_list);

#endif
