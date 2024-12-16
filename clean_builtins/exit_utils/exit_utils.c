/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:42:33 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 18:46:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	free_double_pointer(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_lexer(t_lexer *lexer)
{
	t_lexer	*temp;

	while (lexer)
	{
		temp = lexer;
		lexer = lexer->next;
		if (temp->token)
			free(temp->token);
		free(temp);
	}
}

void	free_parser(t_parser *parser)
{
	t_parser	*tmp;

	while (parser)
	{
		tmp = parser;
		parser = parser->next;
		free(tmp->heredoc_name);
		free(tmp->heredoc_delim);
		if (tmp->redirections)
			free_lexer(tmp->redirections);
		if (tmp->commands)
			free_double_pointer(tmp->commands);
		free(tmp);
	}
}

void	free_everything(t_mini *data)
{
	free_double_pointer(data->original_env);
	free_env_list(data->env);
	free_env_list(data->export);
	free_parser(data->parser);
}
