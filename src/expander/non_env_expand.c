
#include "../../includes/mini.h"

char	*handle_question_mark(char *string, int start, int exit_code, int *i)
{
	char	*tmp;
	char	*before_var;
	char	*after_var;
	char	*exit_string;

	exit_string = ft_itoa(exit_code);
	if (start == 1 && string[2] == '\0')
	{
//		free(string);
		string = exit_string;
		*i = (int)ft_strlen(string) - 1;
	}
	else
	{
		before_var = ft_substr(string, 0, start - 1);
		if (string[start + 1] == '\0')
		{
//			free(string);
			string = ft_strjoin(before_var, exit_string);
			*i = (int)ft_strlen(string) - 1;
		}
		else
		{
			after_var = ft_substr(string, start + 1, ft_strlen(string) - 1);
//			free(string);
			tmp = ft_strjoin(before_var, exit_string);
			*i = (int)ft_strlen(tmp) - 1;
			string = ft_strjoin(tmp, after_var);
//			free(after_var);
//			free(tmp);
		}
//		free(before_var);
//		free(exit_string);
	}
	return (string);
}

char	*unmatched_var(char *string, int start, int end, int *i)
{
	char	*before_var;
	char	*after_var;

	if (start == 1 && string[end + 1] == '\0')
	{
		*i = 0;
		free(string);
		string = ft_strdup("\0");
	}
	else
	{
		before_var = ft_substr(string, 0, start - 1);
		if (string[end + 1] == '\0')
		{
			string = before_var;
			*i = (int)ft_strlen(string) - 1;
		}
		else
		{
			after_var = ft_substr(string, end + 1, ft_strlen(string) - 1);
			string = ft_strjoin(before_var, after_var);
			*i = (int)ft_strlen(before_var) - 1;
		}
	}
	return (string);
}

