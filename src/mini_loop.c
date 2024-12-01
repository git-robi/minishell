/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/27 13:56:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	print_lexer_list(t_lexer *lexer_list)
{
	t_lexer *tmp = lexer_list;
	int	i = 1;
	
	if (lexer_list == NULL)
		printf("lexer is empty");
	while (tmp)
	{	
		printf("redirection [%d] word: ", i);
		printf("%s\n", tmp->token);
		printf("type: [%d]\n", tmp->type);
		if (tmp->next)
			printf("%s has next: %s\n", tmp->token, tmp->next->token);
		if (tmp->prev)
			printf("%s has prev: %s\n", tmp->token, tmp->prev->token);
		printf("\n");
		tmp = tmp->next;
		i++;
	}
}

void	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("command[%d] = -%s-\n", i + 1, array[i]);
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
		printf("------------NODE %d------------\n", i + 1);
		printf("-------COMMANDS---------\n");
		print_array(tmp->commands);
		if (tmp->redirections)
		{
			printf("----------REDIRECTION LIST----------\n");
			print_lexer_list(tmp->redirections);
		}
		i++;
		tmp = tmp->next;
		printf("\n");
	}
}

void	clear_data(t_mini *data)
{
	if (data->line != NULL)
	{
		free(data->line);
		data->line = NULL;
	}
	if (data->lexer != NULL)
	{
		free_lexer_list(&data->lexer);
		data->lexer = NULL;
	}
	if (data->parser != NULL)
	{
		free_parser_list(&data->parser);
		data->parser = NULL;
	}
	if (data->pids != NULL)
	{
		free(data->pids);
		data->pids = NULL;
	}
	data->in_fd = STDIN_FILENO;
}

void	mini_loop(t_mini *data)
{
	while (1)
	{
		clear_data(data);
		data->line = readline("minishell$ " );
		if (!data->line)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			exit (EXIT_SUCCESS);
		}
		add_history(data->line);
		if (data->line[0] == '\0')
			continue ;
		if (ft_strcmp(data->line, "exit") == 0)
			exit (0);
		if (count_quotes(data->line))
			continue ;
		read_token(data);
		if (unexpected_token_error(error_check(data)))
			continue ;
		parser(data);
//		print_lexer_list(data->lexer);
//		print_parser_list(data->parser);
		expander(data);
		print_parser_list(data->parser);
		executor(data);
	}
}
