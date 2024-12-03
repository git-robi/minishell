#include "../../includes/mini.h"
#include <stdio.h>

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

int	count_quotes(char *line)
{
	int	in_single;
	int	in_double;
	int	total;
	int	i;

	i = 0;
	in_single = 0;
	in_double = 0;
	total = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			if (!in_double && !in_single)
			{
				total++;
				in_double = 1;
			}
			else if (in_double && !in_single)
			{
				total++;
				in_double = 0;
			}
		}
		if (line[i] == '\'')
		{
			if (!in_double && !in_single)
			{
				total++;
				in_single = 1;
			}
			else if (in_single && !in_double)
			{
				total++;
				in_single = 0;
			}
		}
		i++;
	}
	if (total % 2 != 0)
	{
		ft_putstr_fd("quotes not properly closed\n", 2);
		return (1);
	}
	return (0);
}
