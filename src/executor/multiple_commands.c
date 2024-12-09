/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:51 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/27 16:15:35 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	redirect_in_out(t_mini  **data, t_parser *cmd, int pipes_ends[2])
{
	if (cmd->prev)
	{
		/*if(*/dup2((*data)->in_fd, STDIN_FILENO);/*< 0)*/
			//error
		close((*data)->in_fd);
	}
	close(pipes_ends[0]);
	if (cmd->next)
	{
		/*if(*/dup2(pipes_ends[1], STDOUT_FILENO); /*< 0)*/
			//error
	}
//	close(pipes_ends[1]);
}

void	make_process(t_mini **data, t_parser *cmd, int pipes_ends[2])
{
	static int	pid_idx = 0;

	(*data)->pids[pid_idx] = fork();
	if ((*data)->pids[pid_idx] < 0)
		free_data_and_exit(*data, 1);
	else if ((*data)->pids[pid_idx] == 0)
		{
			redirect_in_out(data, cmd, pipes_ends);
			execute_command(*data, cmd);
		}
//	waitpid((*data)->pids[pid_idx], &status, 0);
	pid_idx++;
	if (pid_idx > count_nodes((*data)->parser))
	{
		pid_idx = 0;
		(*data)->in_fd = STDIN_FILENO;
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
	int	exit_code;
	int	i;

	i = 0;
	while (i < count_nodes((*data)->parser))
	{
		waitpid((*data)->pids[i], &exit_code, 0);
		i++;
	}
	if (WIFEXITED(exit_code))
		(*data)->exit_code = WEXITSTATUS(exit_code);
}

void	multiple_commands(t_mini *data)
{
	int	pipes_ends[2];
	t_parser	*cmd;

	cmd = data->parser;
	while (cmd)
	{
		if (cmd->next)
			pipe(pipes_ends);
		check_heredoc(data, cmd);
		make_process(&data, cmd, pipes_ends);
		close(pipes_ends[1]);
		if (cmd->prev)
			close(data->in_fd);
		update_in_fd(&data, cmd, pipes_ends);
		cmd = cmd->next;	
	}
//	close(pipes_ends[0]);
	wait_for_processes(&data);
}
