

void	expand_string(char *string)
{
	
}

void	handle_node_expander(t_parser *node)
{
	int	i;

	i = 0;
	while (node->commands && node->commands[i])
	{
		if (single_quoted(node->commands[i]))
			node->commands[i] = ft_strtrim(node->commands[i], "\'");
		else
		{
			node->commands[i] = ft_strtrim(node->commands[i], "\"");
			expand_string(node->commands[i]);
		}
		i++;
	}
}

void	expander(t_mini *data, t_parser *cmd_list)
{
	t_parser	*tmp;

	tmp = cmd_list;
	while (tmp)
	{
		handle_node_expander(tmp);
		tmp = tmp->next;
	}
}
