/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:54:06 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/06 11:56:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef struct s_parser
{
	char	**commands;
	//builtin function
	int		redir_num;
	//redirection type;
	t_parser	*next;
	t_parser	*prev;
}	t_parser;

int		parser(t_mini *data);
int		error_check(t_mini *data);
int		count_commands(t_mini *data);
void	store_commands(t_mini *data, t_parser *node);

#endif
