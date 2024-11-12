/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:54:06 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/07 14:38:52 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_parser t_parser;

typedef struct s_parser
{
	char	**commands;
	//builtin function
//	int		redir_num; not sure about this
	t_lexer		*redirections;
	t_parser	*next;
	t_parser	*prev;
}	t_parser;

int		parser(t_mini *data);
void	store_commands(t_mini *data, t_parser **node);
t_lexer *remove_pipe(t_mini *data);
void    handle_redirections(t_mini *data, t_parser *node);
void    store_redirection(t_lexer **token, t_parser **parser_node, t_mini *data);

//list utils parser
void    add_node_parser(t_parser *node, t_parser **parser_list);
t_parser        new_node_parser(void);
void    free_node_parser(t_parser **node);

//utils parser
int             count_commands(t_mini *data);
int             error_check(t_mini *data);
void    unexpected_token_error(t_mini *data, t_lexer *node);

#endif
