#include "../../includes/mini.h"

void	expand_string(t_mini *data, char **string)
{
	int	i;
	int	j;
	char	*tmp;
	char	*tmp_str;

	i = -1;
	tmp_str = ft_strdup(*string);
	tmp = ft_strdup(*string);
	while (tmp[++i] != '\0')
	{
		if (tmp[i] == '$')
		{
			while (tmp[i] == '$')
				i++;
			if (tmp[i] == '\0' || is_whitespace(tmp[i]))
				continue ;
			if (tmp[i] == '?')
			{
				tmp_str = handle_question_mark(tmp, i, data->exit_code, &i);
			//	free(tmp);
				tmp = ft_strdup(tmp_str);
				continue ;
			}
			j = i;
			while (tmp[j] != '$' && tmp[j] != '\0' && !is_whitespace(tmp[j]))
				j++;
//			free(tmp_str);
			tmp_str = expand_substring(data, tmp, i, j - 1, &i);
//			free(tmp);
		}
		tmp = ft_strdup(tmp_str);
	}
//	free(tmp);
	*string = tmp_str;
}

void	handle_node_expander(t_mini *data, t_parser *node)
{
	int	i;

	i = 0;
	while (node->commands && node->commands[i])
	{
		if (is_single_quoted(node->commands[i]))
			node->commands[i] = ft_strtrim(node->commands[i], "\'");
		else
		{
			node->commands[i] = ft_strtrim(node->commands[i], "\"");
			expand_string(data, &node->commands[i]);
		}
		i++;
	}
}

void	expander(t_mini *data)
{
	t_parser	*tmp;
	char		**cmd_tmp;

	tmp = data->parser;
	while (tmp)
	{
		handle_node_expander(data, tmp);
		cmd_tmp = strarr_cpy(tmp->commands);
		free_strarr(tmp->commands);
		tmp->commands = cmd_tmp;		
		tmp = tmp->next;
	}
}
