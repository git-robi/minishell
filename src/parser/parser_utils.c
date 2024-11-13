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
#include "../../includes/mini.h"

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
		if (node->type != WORD)
		{
			if (node->next == NULL)
				return (node);
			else if (node->prev->type != WORD || node->next->type != WORD)
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
