/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/23 12:51:38 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	execute_command(t_mini *data, t_parser *cmd)
{
	char	*path;
//consider making **env as a copy of the list to have the variables always updated
	if (cmd->redirections && redirections(cmd) != EXIT_SUCCESS)
		exit (EXIT_FAILURE);
	//if builtin
		//call function to execute builtin
		//return bultin function exit code
	//if not builtin
	path = path_finder(cmd->commands[0], data->env);
	if (path == NULL)
	{
		ft_putstr_fd(cmd->commands[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit (127);
	}
	if (execve(path, cmd->commands, data->env) == -1)
	{
		//print erro message
		exit (127);
	}
	exit (EXIT_SUCCESS);
}

void	one_command(t_mini *data)
{
	int	child_status;
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
	waitpid(pid, &child_status, 0);
//	if (WIFEXITED(child_status))
		//store the exit status(decide in which variable)
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
