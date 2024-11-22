#include "../../includes/mini.h"

void	redirect_in_out(t_mini  *data, t_parser *cmd, int pipes_ends[2], int in_fd)
{
	if (cmd->prev)
	{
		if (dup2(in_fd, STDIN_FILENO) < 0)
			//error
		close(in_fd);
	}
	close(pipes_ends[0]);
	if (cmd->next)
	{
		if (dup2(pipes_ends[1], STDOUT_FILENO) < 0)
			//error
	}
	close(pipes_ends[1]);
}

void	make_process(t_mini *data, t_parser *cmd, int pipes_ends[2])
{
	static int	pid_idx = 0;
	static int	in_fd = STDIN_FILENO;

	
	data->pids[i] = fork();
	if (data->pids[i] < 0)
		//error forking
	else if (data->pids == 0)
		redirect_in_out(data, cmd, pipes_ends, in_fd);
	pid_idx++;
	if (pid_idx == count_nodes(data->parser))
	{
		pid_idx = 0;
		in_fd = STDIN_FILENO;
	}
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
		make_process(data, cmd, pipes_ends);
		execute_command(data, cmd);
		//AND THEN????
	
		cmd = cmd->next;	
	}
}
