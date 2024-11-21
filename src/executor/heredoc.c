#include "../../includes/mini.h"

void	handle_quotes_heredoc(t_parser **cmd, t_lexer **heredoc)
{
	int	end;

	end = ft_strlen((*heredoc)->token) - 1;
	(*cmd)->heredoc_delim = (*heredoc)->token;
	if ((*heredoc)->token[0] == '\'' && (*heredoc)->token[end] == '\'')
		(*cmd)->heredoc_delim = ft_strtrim((*heredoc)->token, "\'");
	else if ((*heredoc)->token[0] == '\"' && (*heredoc)->token[end] == "\"")
		(*cmd)->heredoc_delim = ft_strtrim((*heredoc)->token, "\"");
}

int	make_heredoc(t_parser **cmd, t_lexer **heredoc)
{
	//in this function will be necessary to handle the "Ctrl+C" signal
	char	*line;
	int	heredoc_fd;

	heredoc_fd = open((*cmd)->heredoc_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	//handle open error
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, (*cmd)->herdoc_delim) == 0)
		{
			free(line);
			break ;
		}
		//call expander
		write(heredoc_fd, line, ft_strlen(line));
		write(heredoc_fd, "\n", 1);
		free(line);
	}
	close(heredoc_fd);
	//check for errors and return failure exit status in case of error
	return (0);
}

char *new_heredoc_name(void)
{
	static int	hd_num = -1;
	char	*heredoc_name;
	char	*heredoc_num;

	hd_num++;
	heredoc_num = ft_itoa(hd_num);
	//check for malloc fail?
	heredoc_name = ft_strjoin("heredoc_n.", heredoc_num);
	//check for malloc fail?
	free(heredoc_num);
	return (heredoc_name);
}

int	handle_heredoc(t_parser **cmd, t_lexer **heredoc)
{
	int	return_value;

	if ((*cmd)->heredoc_name)
		free((*cmd)->heredoc_name);
	(*cmd)->heredoc_name = new_heredoc_name();
	handle_quotes_heredoc(cmd, heredoc);
	make_heredoc(cmd, heredoc);
	
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
			return_value = handle_heredoc(&cmd, &redir_tmp);
			if (return_value != 0)
				// WHAT HAPPENS IF HEREDOC FAILS????
		}
		redir_tmp = redir_tmp->next;
}
