/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/20 11:41:44 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	handle_in_out(t_data *mini, t_parser *cmd, int pipes_ends[2], int in_fd)
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
	execute_command(data, cmd);

}

void	make_processes(t_mini *data, t_parser *cmd, int	pipes_ends[2])
{
	static int	pid_idx = 0;
	static int	in_fd = STDIN_FILENO;

	
	data->pids[i] = fork();
	if (data->pids[i] < 0)
		//error forking
	else if (data->pids == 0)
		handle_in_out();
	pid_idx++;
	
	if (pid_idx == count_nodes(data->parser))
	{
		pid_idx = 0;
		in_fd = STDIN_FILENO;
	}
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

void	execute_multiple_commands(t_mini *data)
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
		make_process(data, cmd, 

		//AND THEN????
	
		cmd = cmd->next;	
	}
}

int	count_nodes(t_parser *parser_list)
{
	int			nodes;
	t_parser	*tmp;

	nodes = 0;
	tmp = parser_list;
	while(tmp)
	{
		nodes++;
		tmp = tmp->next;
	}
	return (nodes);
}

void	executor(t_mini *data)
{
	int		commands;

	commands = count_nodes(data->parser);
	if (commands == 1)
		//call function that executes a single command
	else
	{
		//create array to store the process IDs of the child processes:
		data->pids = (int *)malloc(sizeof(int) * commands);
		if (data->pids == NULL)
			//free and exit
		execute_multiple_commands(data);
	}
}
