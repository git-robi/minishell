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

int	execute_command(t_mini *data, t_parser *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->redirections)
		exit_code = redirections(cmd);
	if (exit_code != EXIT_SUCCESS)
		return (exit_code);
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
	int	pid;

	//expand
	//if builtin
		//execute builtin 
	check_heredoc(data, data->parser);
	pid = fork();
	if (pid < 0)
		//error
	if (pid == 0)
		execute_command(data, data->parser);
	//wait for child process to finish
	//store child process exit value 
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
