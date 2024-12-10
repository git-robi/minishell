
#include "../../includes/mini.h"

char	*expand_and_reassemble(char *string, int start, int end, char *expansion, int *i)
{
	char	*before_var;
	char	*after_var;
	char	*tmp;

	tmp = NULL;
	after_var = NULL;
	before_var = ft_substr(string, 0, start - 1);
	if (string[end + 1] == '\0')
	{
		string = ft_strjoin(before_var, expansion);
		*i = (int)ft_strlen(string) - 1;
	}
	else
	{
		after_var = ft_substr(string, end + 1, ft_strlen(string) - 1);
		tmp = ft_strjoin(before_var, expansion);
		*i = (int)ft_strlen(tmp) - 1;
		string = ft_strjoin(tmp, after_var);
	}
	return (string);
}

char	*expand_var(char *string, int start, int end, char *expansion, int *i)
{
	if (start == 1 && string[end + 1] == '\0')
	{
		string = ft_strdup(expansion);
		*i = (int)ft_strlen(expansion) - 1;
	}
	else
		string = expand_and_reassemble(string, start, end, expansion, i);
	return (string);
}

char	*expand_substring(t_mini *data, char *string, int start, int end, int *i)
{
	t_env	*tmp;
	char	*substring;
	char	*tmp_var;

	tmp = data->env_list;
	substring = ft_substr(string, start, end - start + 1);
	while (tmp)
	{
		tmp_var = ft_substr(tmp->variable, 0, ft_strlen(tmp->variable) - 1);
		if (!ft_strcmp(tmp_var, substring) && tmp->content)
		{
			free(tmp_var);
			free (substring);
			return (expand_var(string, start, end, tmp->content, i));
		}
		tmp = tmp->next;
		free(tmp_var);
	}
	free(substring);
	return (unmatched_var(string, start, end, i));
}
