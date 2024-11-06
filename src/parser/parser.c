/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:22 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/06 13:13:11 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/lexer.h"	

void	store_commands(t_mini *data, t_parser *node)
{
	int	cmds_num;
	int	i;

	i = 0;
	cmds_num = count_commands(data);
	data->parser.commands = calloc(sizeof(char *) * cmds_num + 1);
	if (data->parser.commands == NULL)
		exit (0); //create function for error and exit
	
	
}

int	parser(t_mini *data)
{
	t_parser	*node;
	
	node = NULL;
	if (error_check(data))
		return (code); //create function for error and exit
	while (data->lexer)
	{
		store_commands(data, node);
		
	}
}
	
