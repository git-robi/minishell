#include "../../includes/mini.h"

void	redirect_in_out(t_mini  **data, t_parser *cmd, int pipes_ends[2])
{
	if (cmd->prev)
	{
		if (dup2((*data)->in_fd, STDIN_FILENO) < 0)
			//error
		close((*data)->in_fd);
	}
	close(pipes_ends[0]);
	if (cmd->next)
	{
		if (dup2(pipes_ends[1], STDOUT_FILENO) < 0)
			//error
	}
	close(pipes_ends[1]);
}

void	make_process(t_mini **data, t_parser *cmd, int pipes_ends[2])
{
	static int	pid_idx = -1;

	pid_idx++;
	if (pid_idx == count_nodes((*data)->parser))
	{
		pid_idx = 0;
		(*data)->in_fd = STDIN_FILENO;
	}
	(*data)->pids[pid_idx] = fork();
	if ((*data)->pids[pid_idx] < 0)
		//error forking
	else if ((*data)->pids == 0)
	{
		redirect_in_out(data, cmd, pipes_ends);
		execute_command();
	}
}

void	update_in_fd(t_mini **data, t_parser *cmd)
{
	if (cmd->heredoc_name)
	{
		close(end[0]);
		(*data)->in_fd = open(cmd->heredoc_name, O_RDONLY);
	}
	else
		(*data)->in_fd = end[0];
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
	if (WIFEXITED(status))
		//update variable that keeps track of exit code for $?
}

void	multiple_commands(t_mini *data)
{
	int	pipes_ends[2];
	t_parser	*cmd;

	cmd = data->parser;
	while (cmd)
	{
		//call the expander;

		if (cmd->next)
			pipe(pipes_ends);
		check_heredoc(data, cmd);
		make_process(&data, cmd, pipes_ends);
		close(pipes_ends[1]);
		if (cmd->prev)
			close(data->in_fd);
		update_in_fd(&data, cmd);
		cmd = cmd->next;	
	}
	close(pipes_ends[0]);
	wait_for_processes(&data);
}
