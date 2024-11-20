/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:54:06 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/20 10:19:52 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_parser t_parser;

typedef struct s_parser
{
	char	**commands;
	//builtin function
	char		*heredoc_name;
	char		*heredoc_delim;
	t_lexer		*redirections;
	t_parser	*next;
	t_parser	*prev;
}	t_parser;

void		parser(t_mini *data);
void	store_commands(t_mini *data, t_parser **node);
t_lexer *remove_pipe(t_mini *data);
void    handle_redirections(t_mini *data, t_parser *node);
t_lexer    *store_redirection(t_lexer **token, t_parser **parser_node, t_mini *data);

//list utils parser
void    add_node_parser(t_parser *node, t_parser **parser_list);
t_parser        *new_node_parser(void);
void    free_node_parser(t_parser **node);

//utils parser
int             count_commands(t_mini *data);
t_lexer             *error_check(t_mini *data);
int    unexpected_token_error(t_lexer *node);

#endif
