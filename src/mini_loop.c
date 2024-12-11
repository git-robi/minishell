/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/10 12:36:27 by rgiambon         ###   ########.fr       */
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
		printf("[%d] word: ", i);
		printf("%s\n", tmp->token);
//		printf("type: [%d]\n", tmp->type);
//		if (tmp->next)
//			printf("%s has next: %s\n", tmp->token, tmp->next->token);
//		if (tmp->prev)
//			printf("%s has prev: %s\n", tmp->token, tmp->prev->token);
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

int	continue_case(char *line)
{
	int	i;
	
	i = 0;
	if (line[0] == '\0')
		return (1) ;
	if (line[0] == '\t')
		return (1);
	if (count_quotes(line))
		return (1);
	while (line[i])
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
		if (line[i] == '\0')
			return (1);
	}
	return (0);
}

void	mini_loop(t_mini *data)
{
	while (1)
	{
		clear_data(data);
		data->line = readline("minishell$ " );
		if (!data->line)
		{
			ft_putstr_fd("exit", STDOUT_FILENO);
			exit (EXIT_SUCCESS);
		}
		add_history(data->line);
		if (continue_case(data->line))
			continue ;
		if (ft_strcmp(data->line, "exit") == 0)
			exit (0);
		read_token(data);
		if (unexpected_token_error(error_check(data)))
			continue ;
		parser(data);
//		print_one_by_one(data->parser);
//		print_parser_list(data->parser);
		expander(data);
		executor(data);
	}
}
