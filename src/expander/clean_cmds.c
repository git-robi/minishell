#include "../../includes/mini.h"

int	count_marker(char *str, char marker)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == marker)
			count++;
		i++;
	}
	return (count);
}

void	clean_markers(t_mini *data)
{
	t_parser	*node;
	t_lexer		*redir;
	int		i;

	node = data->parser;
	while (node)
	{
		i = 0;
		while (node->commands && node->commands[i])
		{
			node->commands[i] = remove_marker(data, node->commands[i], \
			count_marker(node->commands[i], '\x02'), '\x02');
			node->commands[i] = remove_marker(data, node->commands[i], \
			count_marker(node->commands[i], '\x03'), '\x03');
			i++;
		}
		redir = node->redirections;
		while (redir)
		{
			redir->token = remove_marker(data, redir->token, \
			count_marker(redir->token, '\x02'), '\x02');
			redir->token = remove_marker(data, redir->token, \
			count_marker(redir->token, '\x03'), '\x03');
			redir = redir->next;
		}
		node = node->next;
	}
}

void	clean_spaces(t_mini *data)
{
	t_parser	*node;
	int		i;

	node = data->parser;
	while (node)
	{
		i = 0;
		while (node->commands && node->commands[i])
		{
			clean_cmd(node->commands[i]);	
			i++;
		}
		node = node->next;
	}
}
void	clean_cmd(char *cmd)
{
	int	i;
	int	in_quotes;
	int	in_var;

	in_quotes = 0;
	in_var = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"')
			in_quotes = !in_quotes;
		if (cmd[i] == '\x02')
			in_var = !in_var;
		if (cmd[i] == ' ' && cmd[i + 1] == ' ' && !in_quotes && in_var)
			cmd[i] = '\x03';
		i++;
	}
}
