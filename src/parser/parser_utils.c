/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:54:27 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/11 09:45:04 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/parser.h"
#include "../../includes/lexer.h"

void	count_quotes(t_mini *data)
{
	int	in_single;
	int	in_double;
	int	total;
	int	i;

	i = 0;
	in_single = 0;
	in_double = 0;
	total = 0;
	while (data->line[i])
	{
		if (data->line[i] == '"')
		{
			if (!in_double && !in_single)
				in_double = 1;
			else if (in_double)
				in_double = 0;
			total++;
		}
		if (data->line[i] == ''')
		{
			if (!in_double && !in_single)
				in_single = 1;
			else if (in_single)
				in_single = 0;
			total++;
		}
		i++;
	}
	if (total % 2 != 0)
		unclosed_quotes_error();
} 	
	
	
}

void	unexpected_token_error(t_mini *data, t_lexer *node)
{
	if (node != NULL)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token '", STDERR_FILENO);
		ft_putstr_fd(node->token, STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
		free_data_and_exit(data, EXIT_FAILURE);
	}
}

t_lexer	*error_check(t_mini *data)
{
	t_lexer	*node;

	node = data->lexer;
	if (node->type == PIPE)
		return (node);
	node = node->next;
	while (node)
	{
		if (node->type == != WORD)
		{
			if (node->next == NULL)
				return (node);
			else if (node->prev.type != WORD || node->next.type != WORD)
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}

int	count_commands(t_mini *data)
{
	int	cmds_num;
	t_lexer	*tmp;

	cmds_num = 0;
	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		cmds_num++;
		tmp = tmp->next;
	}
	return (cmds_num);
}
