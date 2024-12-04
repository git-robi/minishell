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
