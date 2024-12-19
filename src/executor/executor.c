/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/18 18:57:34 by rgiambon         ###   ########.fr       */
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

static int count_words(char **commands) {
    int count = 0;

    for (int i = 0; commands[i]; i++) {
        char *command = commands[i];
        int in_word = 0;
        for (int j = 0; command[j]; j++) {
            if (!isspace(command[j]) && !in_word) {
                in_word = 1;
                count++;
            } else if (isspace(command[j])) {
                in_word = 0;
            }
        }
    }

    return count;
}

// Function to replace markers with spaces
void replace_marker(char **commands) {
    int i = 0;
    int j;

    while (commands[i]) {
        j = 0;
        while (commands[i][j]) {
            if (commands[i][j] == '\x03' || commands[i][j] == '\x05') {
                commands[i][j] = ' ';
            }
            j++;
        }
        i++;
    }
}

// Function to create the parsed commands array without strtok
char **make_commands_cpy(char **commands) {
    int total_words = count_words(commands);
    char **result = (char **)malloc((total_words + 1) * sizeof(char *));
    int index = 0;

    for (int i = 0; commands[i]; i++) {
        char *command = commands[i];
        int start = 0, end = 0;

        while (command[start]) {
            // Skip leading spaces
            while (command[start] && isspace(command[start])) {
                start++;
            }
            end = start;

            // Find the end of the current word
            while (command[end] && !isspace(command[end])) {
                end++;
            }

            if (end > start) {
                // Extract the word
                int word_length = end - start;
                result[index] = (char *)malloc((word_length + 1) * sizeof(char));
                strncpy(result[index], command + start, word_length);
                result[index][word_length] = '\0';
                index++;
            }
            start = end;
        }
    }

    result[index] = NULL; // Null-terminate the array
    replace_marker(result);
    return result;
}

void	execute_command(t_mini *data, t_parser *cmd)
{
	char	*path;
	char	**env;
	char	**commands;

	commands = make_commands_cpy(cmd->commands);
	if ((!cmd->commands || !cmd->commands[0]) && !cmd->redirections)
		exit (EXIT_SUCCESS);
	if (cmd->commands && is_a_directory(cmd->commands[0]))
		exit (directory_path(cmd->commands[0]));
	if (cmd->redirections && redirections(cmd) != EXIT_SUCCESS)
		exit (EXIT_FAILURE);
	if (cmd->builtin)
		exit (call_builtin_function(data, cmd));
	if ((!cmd->commands || !cmd->commands[0]))
		exit(EXIT_SUCCESS);
	env = env_list_to_strarr(data);
	path = path_finder(commands[0], env);
	if (path == NULL)
	{
		ft_putstr_fd(commands[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		free_strarr(commands);
		exit (127);
	}
	execve(path, commands, env);
	free_strarr(env);
	free_strarr(commands);
	exit (EXIT_SUCCESS);
}

void	one_command(t_mini *data)
{
	int			child_status;
	int			pid;
	t_parser	*cmd;

	cmd = data->parser;
	if (builtin(data, cmd))
		return ;
	check_heredoc(data, data->parser);
	if (g_status != 0)
		return ;
	pid = fork();
	if (pid < 0)
		free_data_and_exit(data, 1);
	if (pid == 0)
		execute_command(data, data->parser);
	waitpid(pid, &child_status, 0);
	if (WIFEXITED(child_status))
		data->exit_code = WEXITSTATUS(child_status);
	if (g_status != 0)
	{
		data->exit_code = g_status;
		printf("\n");
	}
}

void	executor(t_mini *data)
{
	int		commands;

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
	remove_heredoc();
}
