/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/13 13:06:23 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"
#include <dirent.h>

int	directory_path(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": is a directory\n", STDERR_FILENO);
	return (126);
}

int	is_a_directory(char *cmd)
{
	DIR	*dir;

	dir = opendir(cmd);
	if ((cmd[0] == '/' || cmd[0] == '.') && dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	closedir(dir);
	return (0);
}

void	execute_command(t_mini *data, t_parser *cmd)
{
	char	*path;
	char	**env;

	if (!cmd->commands || !cmd->commands[0])
		exit (EXIT_SUCCESS);
	if (is_a_directory(cmd->commands[0]))
		exit (directory_path(cmd->commands[0]));
	if (cmd->redirections && redirections(cmd) != EXIT_SUCCESS)
		exit (EXIT_FAILURE);
	if (cmd->builtin)
		exit (call_builtin_function(data, cmd));
	env = env_list_to_strarr(data);
	path = path_finder(cmd->commands[0], env);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->commands[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit (127);
	}
	execve(path, cmd->commands, env);
	free_strarr(env);
	exit (EXIT_SUCCESS);
}

void	one_command(t_mini *data)
{
	int			child_status;
	int			pid;
	t_parser	*cmd;

	signal(SIGQUIT, handle_sigquit);
	cmd = data->parser;
	if (cmd->builtin && builtin_in_parent(cmd->commands[0]))
	{
		data->exit_code = call_builtin_function(data, cmd);
		return ;
	}
	check_heredoc(data, data->parser);
	pid = fork();
	if (pid < 0)
		free_data_and_exit(data, 1);
	if (pid == 0)
		execute_command(data, data->parser);
	waitpid(pid, &child_status, 0);
	if (WIFEXITED(child_status))
		data->exit_code = WEXITSTATUS(child_status);
	else if (WIFSIGNALED(child_status))
	{
		if (WTERMSIG(child_status) == SIGINT)
			data->exit_code = 130;
		else if (WTERMSIG(child_status) == SIGQUIT)
			data->exit_code = 131;
	}
}

void	executor(t_mini *data)
{
	int		commands;

//	signal(SIGQUIT, handle_sigquit);
	g_status = 0;
	commands = count_nodes(data->parser);
	if (commands > 1)
	{
		data->pids = (int *)malloc(sizeof(int) * commands);
		if (data->pids == NULL)
			free_data_and_exit(data, 1);
		multiple_commands(data);
	}
	else
		one_command(data);
	if (g_status != 0)
	{
		data->exit_code = g_status;
		printf("\n");

	}
}
