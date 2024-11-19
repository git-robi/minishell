#include "../../includes/mini.h"

void	check_heredoc(t_mini *data, t_parser *cmd)
{
	int	return_value;
	t_parser	*redir_tmp;

	redir_tmp = cmd->redirections;
	while (redir_tmp)
	{
		if (redir_tmp == HERE_DOC)
		{
			if (cmd->here_doc)
				free(cmd->here_doc);
			cmd->here_doc = new_heredoc_file();
			return_value = handle_heredoc();
			if (return_value != 0)
				// WHAT HAPPENS IF HEREDOC FAILS????
		}
		redir_tmp = redir_tmp->next;
}

void	multiple_commands(t_mini *data)
{
	int	fd_in;
	int	pipes_ends[2];
	t_parser	*cmd;
	
	fd_in = STDIN_FILENO;
	cmd = data->parser;
	while (cmd)
	{
		//call the expander;

		//set up pipes
		if (cmd->next)
			pipe (pipes_ends);
		check_heredoc(data, cmd);

	//handle heredoc

	//AND THEN????
	
		cmd = cmd->next;	
	}

		
}

void	executor(t_mini *data)
{
	//if there are zero pipes:
		//call function that executes a single command
	
	//else
		//create array to store the process IDs of the child processes
		//call function that executes all commands with pipes
}
	
