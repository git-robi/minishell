#include "../../includes/mini.h"


int	is_double_quoted(char *str)
{
	if (str[0] == '\"' && str[ft_strlen(str) - 1] == '\"')
		return (1);
	return (0);
}

int	is_single_quoted(char *str)
{
	if (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
}

int	count_quotes(char *line) 
{
	int in_single = 0;
	int in_double = 0;
	int i = 0;

	in_single = 0;
	in_double = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '"' && !in_single)
			in_double = !in_double;
		else if (line[i] == '\'' && !in_double)
			in_single = !in_single;
		i++;
	}
	if (in_single || in_double)
	{
		ft_putstr_fd("quotes not properly closed\n", 2);
		return 1;
	}
	return 0;
}
