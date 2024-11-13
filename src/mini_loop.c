/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/11 09:31:17 by rgiambon         ###   ########.fr       */
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
		printf("1\n");
		count_quotes(data->line, data);
		printf("2\n");
		read_token(data);
		print_lexer_list(data->lexer);
		printf("3\n");
		parser(data);
		printf("4\n");
		free(data->line);
	}
}
