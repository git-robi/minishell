#include "../../includes/mini.h"
#include <stdio.h>

int	store_token_in_quotes(char *input, t_lexer **token_list)
{
	int	end;
	t_lexer	*new_node;

	end = 1;
	if (input[0] == '\'')
	{
		while (input[end] != '\'')
			end++;
	}
	else if (input[0] == '\"')
	{
		while (input[end] != '\"')
		end++;
	}
	new_node = new_node_lexer(ft_substr(input, 1, end - 1), WORD);
	if (new_node == NULL)
		return (-1);
	add_node_lexer(new_node, token_list);
	return (end + 1);
}

void	count_quotes(char *line, t_mini *data)
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
		free_data_and_exit(data, EXIT_FAILURE);
	}	
}
