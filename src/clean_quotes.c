#include "../includes/mini.h"

#define MARKER '\x01'

void	replace_quotes(char *str, int *marker_count)
{
	int	first_double;
	int	second_double;
	int	i;
	int	first_single;
	int	second_single;

	first_double = -1;
	second_double = -1;
	first_single = -1;
	second_single = -1;
	i = 0;
	while (str[i])
	{
		if (first_double == -1 && str[i] == '\"' && first_single == -1)
			first_double = i;
		else if (first_double != -1 && str[i] == '\"')
			second_double = i;	
		else if (first_single == -1 && str[i] == '\'' && first_double == -1)
			first_single = i;
		else if (first_single != -1 && str[i] == '\'')
			second_single = i;

		if (first_single != -1 && second_single != -1)
		{
			str[first_single] = MARKER;
			str[second_single] = MARKER;
			*marker_count += 2;
			first_single = -1;
			second_single = -1;
		}
		else if (first_double != -1 && second_double != -1)		
		{
			str[first_double] = MARKER;
			str[second_double] = MARKER;
			*marker_count += 2;
			first_double = -1;
			second_double = -1;
		}
		i++;
	}
}

char	*remove_marker(char *str, int marker_count)
{
	char	*new_string;
	int	i;
	int	j;

	j = 0;
	i = -1;
	new_string = malloc(sizeof(char) * (ft_strlen(str) - marker_count) + 1);
	// protect malloc
	while (str[++i])
	{
		if (str[i] == MARKER)
			continue ;	
		new_string[j] = str[i];
		j++;
	}
	free(str);
	new_string[j] = '\0';
	return (new_string);

}

void    clean_quotes(t_mini *data)
{
	int	i;
	t_parser	*tmp;
	int	marker_count;

	i = 0;
	marker_count = 0;
	tmp = data->parser;
	while (tmp)
	{
		while (tmp->commands && tmp->commands[i])
		{
			//replace_quotes(tmp->commands[i], &marker_count, '\'');
			//replace_quotes(tmp->commands[i], &marker_count, '\"');
			replace_quotes(tmp->commands[i], &marker_count);
			tmp->commands[i] = remove_marker(tmp->commands[i], marker_count);
			i++;
		}
		tmp = tmp->next;
	}
}		
