/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/14 11:45:18 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "../includes/mini.h"

void	print_lexer_list(t_lexer *lexer_list)
{
	t_lexer *tmp = lexer_list;
	int	i = 1;
	while (tmp)
	{	
		printf("redirection [%d] word: ", i);
		printf("%s\n", tmp->token);
		printf("type: [%d]\n", tmp->type);
		tmp = tmp->next;
		i++;
	}
}

void	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("command[%d] = %s\n", i + 1, array[i]);
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
		if (data->line[0] == '\0')
			continue ;
		if (ft_strncmp(data->line, "exit", ft_strlen(data->line)) == 0)
			exit (0);
		count_quotes(data->line, data);
		read_token(data);
//		print_lexer_list(data->lexer);
		parser(data);
		print_parser_list(data->parser);
//		free_data_and_exit(data, -1);
	}
}
