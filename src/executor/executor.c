#include "../../includes/mini.h"


void	handle_quotes_heredoc(t_lexer **heredoc)
{
	int	end;
	char	*delimiter;

	delimiter = (*heredoc)->token;
	end = ft_strlen(delimiter) - 1;
	if (delimiter[0] == '\'' && delimiter[end] == '\'')
	{
		heredoc->quotes = SINGLE_QUOTED;
		delimiter = ft_strtrim(delimiter, "\'");
	}
	else if (delimiter[0] == '\"' && delimiter[end] == "\"")
	{
		(*heredoc)->quotes = DOUBLE_QUOTED;
		delimiter = ft_strtrim(delimiter, "\"");
	}
	free((*heredoc)->token);
	(*heredoc)->token = delimiter;
}

int	make_heredoc(t_lexer *heredoc, char *heredoc_name, )
{
	char	*line;
	int	heredoc_fd;

	heredoc_fd = open(heredoc_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline("> ");
	//handle input
	free(line);
	close(heredoc_fd);
	//check for errors and return failure exit status in case of error
	return (0);
}

void	handle_heredoc(t_lexer *heredoc, char *heredoc_name)
{
	handle_quotes_heredoc(&heredoc);
	make_heredoc(heredoc, heredoc_name, );
	
}

void	check_heredoc(t_mini *data, t_parser *cmd)
{
	int	return_value;
	t_parser	*redir_tmp;

	redir_tmp = cmd->redirections;
	while (redir_tmp)
	{
		if (redir_tmp->type == HERE_DOC)
		{
			if (cmd->here_doc)
				free(cmd->here_doc);
			cmd->heredoc_name = new_heredoc_name();
			return_value = handle_heredoc(redir_tmp, cmd->heredoc_name, );
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
	
	else
		//create array to store the process IDs of the child processes
		multiple_commands(data);
}
