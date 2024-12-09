#include "../../includes/mini.h"

void	expand_string(t_mini *data, char **string)
{
	int	i;
	int	j;
	char	*tmp;
	char	*tmp_str;
	int	single_quote;
	int	double_quote;

	single_quote = 0;
	double_quote = 0;
	i = -1;
	tmp_str = ft_strdup(*string);
	tmp = ft_strdup(*string);
	while (tmp[++i] != '\0')
	{
		if (tmp[i] == '\'' && (double_quote == 0 || double_quote % 2 == 0))
			single_quote++;
		if (tmp[i] == '\"' && (single_quote == 0 || single_quote % 2 == 0))
			double_quote++;
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
			while (tmp[j] != '$' && tmp[j] != '\0' && !is_whitespace(tmp[j]) && !is_quote(tmp[j]))
				j++;
//			free(tmp_str);
			if (single_quote == 0 || single_quote % 2 == 0)
				tmp_str = expand_substring(data, tmp, i, j - 1, &i);
			free(tmp);
		}
		tmp = ft_strdup(tmp_str);
	}
//	free(tmp);
	*string = tmp_str;
}

void	expander(t_mini *data)
{
	t_parser	*tmp;
	char		**cmd_tmp;
	int	i;

	tmp = data->parser;
	while (tmp)
	{
		i = -1;
		while (tmp->commands[++i])
			expand_string(data, &tmp->commands[i]);
		cmd_tmp = strarr_cpy(tmp->commands);
		free_strarr(tmp->commands);
		tmp->commands = cmd_tmp;		
		tmp = tmp->next;
	}
	clean_quotes(data);
}
