#include "../../includes/mini.h"

char	*expand_var(char *string, int start, int end, char *expansion, int *i)
{
	char	*before_var;
	char	*after_var;
	char	*tmp;

	tmp = NULL;
	after_var = NULL;
	
	if (start == 1 && string[end + 1] == '\0')
	{
		string = ft_strdup(expansion);
		*i = (int)ft_strlen(expansion) - 1;
	}
	else
	{
		before_var = ft_substr(string, 0, start - 1);
		if (string[end + 1] == '\0')
		{
			free(string);
			string = ft_strjoin(before_var, expansion);
			*i = (int)ft_strlen(string) - 1;
		}
		else
		{
			after_var = ft_substr(string, end + 1, ft_strlen(string) - 1);
			free(string);
			tmp = ft_strjoin(before_var, expansion);
			*i = (int)ft_strlen(tmp) - 1;
			string = ft_strjoin(tmp, after_var);
			free(after_var);
			free(tmp);
		}
	}
	return (string);
//	printf("string in expand_var: %s\n", string); 
	free(before_var);
}

char	*expand_substring(t_mini *data, char *string, int start, int end, int *i)
{
	t_env	*tmp;
	char	*substring;
	char	*tmp_var;

	tmp = data->env_list;
	substring = ft_substr(string, start, end - start + 1);
//	printf("substring: %s-\n", substring);
	while (tmp)
	{
		tmp_var = ft_substr(tmp->variable, 0, ft_strlen(tmp->variable) - 2);
		if (!ft_strcmp(tmp_var, substring))
			return (expand_var(string, start, end, tmp->content, i));
	//	else
			//check for behaviour when wrong variable
		tmp = tmp->next;
		free(tmp_var);
	}
	free(substring);
	return (NULL);
}

void	expand_string(t_mini *data, char **string)
{
	int	i;
	int	j;
	char	*tmp;
	char	*tmp_str;

	i = -1;
	tmp_str = ft_strdup(*string);
	tmp = ft_strdup(*string);
//	printf("entered expand_string\n");
	while (tmp[++i] != '\0')
	{
		if (tmp[i] == '$')
		{
			
//			if (tmp[i + 1] == '?')
//			{
		//		tmphandle_question_mark(string, i + 1);
			//	continue ;
//			}
			j = i + 1;
			while (tmp[j] != '$' && tmp[j] != '\0' && !is_whitespace(tmp[j]))
				j++;
//			printf("substring = %s\n", ft_substr(tmp, i, j - i));
			free(tmp_str);
			tmp_str = expand_substring(data, tmp, i + 1, j - 1, &i);
			free(tmp);
		}
		tmp = ft_strdup(tmp_str);
	}
	free(tmp);
	*string = tmp_str;
	
		
}

int	is_single_quoted(char *str)
{
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
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

	tmp = data->parser;
	while (tmp)
	{
		handle_node_expander(data, tmp);
		tmp = tmp->next;
	}
}
