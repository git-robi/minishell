/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:22 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/07 14:43:18 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/lexer.h"	

void	store_redirection(t_lexer *tmp, t_parser *node)
{
	t_lexer	*new_node;

	

void	handle_redirections(t_mini *data, t_parser *node)
{
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		if (tmp->type != WORD)
		{
			store_redirection(tmp, node);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}
		  

void	store_commands(t_mini *data, t_parser *node)
{
	int	cmds_num;
	int	i;

	i = 0;
	handle_redirections(data, node);
	cmds_num = count_commands(data);
	data->parser.commands = calloc(sizeof(char *) * cmds_num + 1);
	if (data->parser.commands == NULL)
		exit (0); //create function for error and exit
	
	
}

/*int	count_pipes(t_mini *data)
{
	int	pipes_num;
	t_lexer	*tmp;

	pipes_num = 0;
	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->type == PIPE)
			pipes_num++;
		tmp = tmp->next;
	}
	return (pipes_num);
}*/

int	parser(t_mini *data)
{
	t_parser	*node;
	int			pipes_num;

	node = NULL;
	if (error_check(data))
		return (code); //create function for error and exit
//	pipes_num = count_pipes(data);
	while (data->lexer)
	{
		store_commands(data, node);
		
	}
}
	
