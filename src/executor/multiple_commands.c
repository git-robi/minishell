/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:51 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/13 14:30:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	redirect_in_out(t_mini **data, t_parser *cmd, int pipes_ends[2])
{
	if (cmd->prev)
	{
		if (dup2((*data)->in_fd, STDIN_FILENO) < 0)
			free_data_and_exit(*data, 1);
		close((*data)->in_fd);
	}
	close(pipes_ends[0]);
	if (cmd->next)
	{
		if (dup2(pipes_ends[1], STDOUT_FILENO) < 0)
			free_data_and_exit(*data, 1);
	}
}

void	make_process(t_mini **data, t_parser *cmd, int pipes_ends[2], int idx)
{
	(*data)->pids[idx] = fork();
	if ((*data)->pids[idx] < 0)
		free_data_and_exit(*data, 1);
	else if ((*data)->pids[idx] == 0)
	{
		redirect_in_out(data, cmd, pipes_ends);
		execute_command(*data, cmd);
	}
}

void	update_in_fd(t_mini **data, t_parser *cmd, int pipes_ends[2])
{
	if (cmd->heredoc_name)
	{
		close(pipes_ends[0]);
		(*data)->in_fd = open(cmd->heredoc_name, O_RDONLY);
	}
	else
		(*data)->in_fd = pipes_ends[0];
}

void	wait_for_processes(t_mini **data)
{
	int	child_status;
	int	i;

	i = 0;
	while (i < count_nodes((*data)->parser))
	{
		waitpid((*data)->pids[i], &child_status, 0);
		i++;
	}
	if (WIFEXITED(child_status))
		(*data)->exit_code = WEXITSTATUS(child_status);
	if (g_status != 0)
	{
		(*data)->exit_code = g_status;
		printf("\n");
	}
}

void	multiple_commands(t_mini *data)
{
	int			pipes_ends[2];
	t_parser	*cmd;
	int			pid_idx;
	
	pid_idx = 0;
	cmd = data->parser;
	while (cmd)
	{
		if (cmd->next)
			pipe(pipes_ends);
		check_heredoc(data, cmd);
		if (g_status == 130)
			return  ;
		make_process(&data, cmd, pipes_ends, pid_idx);
		close(pipes_ends[1]);
		if (cmd->prev)
			close(data->in_fd);
		update_in_fd(&data, cmd, pipes_ends);
		cmd = cmd->next;
		pid_idx++;
	}
	wait_for_processes(&data);
}
