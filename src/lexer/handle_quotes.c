#include "../../includes/mini.h"
#include <stdio.h>


/*void	delete_inside_quotes(char **line, int start, int end, char quote) 
{
	int	i;
	int	j;

	i = start;
	while (i <= end)
	{
		if ((*line)[i] == quote)
			(*line)[i] = ' ';
		i++;
	}
	while ((*line)[start] == ' ')
		start++;
	while (there_is_space(*line, start, end))
	{
		j = end;	
		while (j > start)
		{
			if ((*line)[j - 1] == ' ')
			{	
				(*line)[j - 1] = (*line)[j];
				(*line)[j] = ' ';
			}
			j--;
		}
	}
	clean_line(line);
}

void	remove_inside_quotes(t_mini *data)
{	
	t_lexer	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if(is_single_quoted(tmp->token))
			delete_inside_quotes(&tmp->token, 1, ft_strlen(tmp->token) - 2, '\'');
		else if (is_double_quoted(tmp->token))
			delete_inside_quotes(&tmp->token, 1, ft_strlen(tmp->token) - 2, '\"');
		tmp = tmp->next;
	}
}

void	delete_quotes(char **line, int start, int end)
{
	int	i;
	int	j;

	i = start;
	while (i <= end)
	{
		if ((*line)[i] == '\''  || (*line)[i] == '\"')
			(*line)[i] = ' ';
		i++;
	}
	while ((*line)[start] == ' ')
		start++;
	while (there_is_space(*line, start, end))
	{
		j = end;	
		while (j > start)
		{
			if ((*line)[j - 1] == ' ')
			{	
				(*line)[j - 1] = (*line)[j];
				(*line)[j] = ' ';
			}
			j--;
		}
	}
}

char	*remove_quotes(char *line)
{
	int	i;
	int j;

	i = 0;
	while (line[i] != '\0')
	{
		while (is_whitespace(line[i]))
			i++;
		j = i;
		while (!is_whitespace(line[j]) && line[j] != '\0')
			j++;
		if (line[j - 1] !=  line[i] || (!is_quote(line[i]) && !is_quote(line[j - 1])))
				delete_quotes(&line, i, j - 1);
		i = j;
	}
	return (line);
}
*/
int	store_token_in_quotes(char *input, t_lexer **token_list)
{
	int	end;
	t_lexer	*new_node;

	end = 1;
	if (input[0] == '\'')
		while (input[end] && !(input[end] == '\'' && (input[end + 1] == '\0' || input[end + 1] == ' ')))
			end++;
	else if (input[0] == '\"')
		while (input[end] && !(input[end] == '\"' && (input[end + 1] == '\0' || input[end + 1] == ' ')))
			end++;
	new_node = new_node_lexer(ft_substr(input, 0, end + 1), WORD);
	if (new_node == NULL)
		return (-1);
	add_node_lexer(new_node, token_list);
	return (end + 1);
}
