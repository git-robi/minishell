/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/20 11:41:44 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int	execute_command()
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	//if redirections
		//handle redirections
	//if builtin 
		//call function to execute builtin
		//return bultin function exit code
	//if not builtin
		//call function to execute
		//return exit code
	return (exit_code);
}

void	one_command(t_mini *data)
{
	//expand
	//if builtin
		//execute builtin 
	//check heredoc
	//create process
	//execute command
}

void	executor(t_mini *data)
{
	int		commands;

	commands = count_nodes(data->parser);
	if (commands > 1)
	{
		data->pids = (int *)malloc(sizeof(int) * commands);
		if (data->pids == NULL)
			//free and exit
		multiple_commands(data);
	}
	else
		one_command(data);
}
