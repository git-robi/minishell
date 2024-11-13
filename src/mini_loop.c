/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/13 14:14:36 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "../includes/mini.h"

void	print_lexer_list(t_lexer *lexer_list)
{
	t_lexer *tmp = lexer_list;

	while (tmp)
	{	
		printf("%s\n", tmp->token);
		tmp = tmp->next;
	}
}

void	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("command[%d] = %s\n", i, array[i]);
		i++;
	}
}

void	print_parser_list(t_parser *parser_list)
{
	t_parser	*tmp;
	int	i = 0;

	tmp = parser_list;
	while (tmp)
	{
		printf("------------NODE %d------------\n", i);
		printf("-------COMMANDS---------\n");
		print_array(tmp->commands);
		if (tmp->redirections)
		{
			printf("----------REDIRECTION LIST----------\n");
			printf("redirection word: ");
			print_lexer_list(tmp->redirections);
			printf("redirection type: %d\n", tmp->redirections->type);
		}
		i++;
		tmp = tmp->next;
	}
}

void	mini_loop(t_mini *data)
{
	while (1)
	{
		data->line = readline("minishell$ " );
		if (!data->line)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			exit (EXIT_SUCCESS);
		}
		add_history(data->line);
		count_quotes(data->line, data);
		read_token(data);
//		print_lexer_list(data->lexer);
		parser(data);
		print_parser_list(data->parser);
		free(data->line);
	}
}
