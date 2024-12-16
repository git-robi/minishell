/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:47:32 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/13 12:58:00 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

char	*env_expand(t_mini *data, char **tmp, char **string)
{
	int	j;
	int	i;

	i = data->exp_idx;
	if ((*tmp)[i] == '\0' || is_whitespace((*tmp)[i]))
		return (*tmp);
	free (*string);
	if ((*tmp)[i] == '?')
		*string = handle_question_mark(data, *tmp, i, data->exit_code);
	else
	{
		j = i;
		while ((*tmp)[j] && (*tmp)[j] != '$'
				&& !is_whitespace((*tmp)[j]) && !is_quote((*tmp)[j]))
			j++;
		*string = expand_substring(data, *tmp, i, j - 1);
	}
	free(*tmp);
	*tmp = ft_strdup(*string);
	return (*tmp);
}

void	expand_string(t_mini *data, char **string)
{
	int		single_quote;
	int		double_quote;
	char	*tmp;

	data->exp_idx = 0;
	single_quote = 0;
	double_quote = 0;
	tmp = ft_strdup(*string);
	while (tmp[data->exp_idx])
	{
		if (tmp[data->exp_idx] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		else if (tmp[data->exp_idx] == '\"' && single_quote == 0)
			double_quote = !double_quote;
		else if (tmp[data->exp_idx] == '$' && single_quote == 0)
		{
			data->exp_idx++;
			tmp = env_expand(data, &tmp, string);
			continue ;
		}
		data->exp_idx++;
	}
	free(tmp);
}
int	space_in_redirection(char *redir)
{
	int	i;
	int	in_single;
	int	in_double;

	in_double = 0;
	in_single = 0;	
	i = 0;
	while (redir[i])
	{
		if (redir[i] == '\"')
			in_double = !in_double;
		if (redir[i] == '\'')
			in_single = !in_single;
		if (!in_single && !in_double && is_whitespace(redir[i]))
			return (1);
		i++;
	}
	return (0);
}

int	expand_redirections(t_mini *data, t_parser *node)
{
	t_lexer	*redir;
	
	redir = node->redirections;
	while (redir)
	{
		if (redir->type != HERE_DOC)
			expand_string(data, &redir->token);
		if (space_in_redirection(redir->token))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("ambiguous redirect\n", 2);
			return (1);
		}
		redir = redir->next;
	}
	return (0);
}

void	clean_spaces(t_mini *data)
{
	t_parser	*node;
	int		i;
	int		j;
	int		in_quotes;
	int		in_var;

	in_var = 0;
	in_quotes = 0;
	node = data->parser;
	while (node)
	{
		i = 0;
		while (node->commands && node->commands[i])
		{
			j = 0;
			while (node->commands[i][j])
			{
				if (node->commands[i][j] == '\"')
					in_quotes = !in_quotes;
				if (node->commands[i][j] == '\x02')
					in_var = !in_var;
				if (node->commands[i][j] == ' ' && node->commands[i][j + 1] == ' ' && !in_quotes && in_var)
					node->commands[i][j] = '\x03';
				j++;
			}
			i++;
		}
		node = node->next;
	}
}

int	count_marker(char *str, char marker)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == marker)
			count++;
		i++;
	}
	return (count);
}

void	clean_markers(t_mini *data)
{
	t_parser	*node;
	t_lexer		*redir;
	int		i;

	node = data->parser;
	while (node)
	{
		i = 0;
		while (node->commands && node->commands[i])
		{
			node->commands[i] = remove_marker(data, node->commands[i], \
			count_marker(node->commands[i], '\x02'), '\x02');
			node->commands[i] = remove_marker(data, node->commands[i], \
			count_marker(node->commands[i], '\x03'), '\x03');
			i++;
		}
		redir = node->redirections;
		while (redir)
		{
			redir->token = remove_marker(data, redir->token, count_marker(redir->token, '\x02'), '\x02');
			redir->token = remove_marker(data, redir->token, count_marker(redir->token, '\x03'), '\x03');
			redir = redir->next;
		}
		node = node->next;
	}
}

int	expander(t_mini *data)
{
	t_parser	*tmp;
	char		**cmd_tmp;
	int			i;

	tmp = data->parser;
	while (tmp)
	{
		i = -1;
		while (tmp->commands && tmp->commands[++i])
		{
			if (!ft_strcmp(tmp->commands[i], "\"$\""))
				continue ;
			expand_string(data, &tmp->commands[i]);
		}
		if(expand_redirections(data, tmp))
			return (1);
		if (tmp->commands)
		{
			cmd_tmp = strarr_cpy(tmp->commands);
			free_strarr(tmp->commands);
			tmp->commands = cmd_tmp;
		}
		tmp = tmp->next;
	}
	clean_spaces(data);
	clean_quotes(data);
	clean_markers(data);
	return (0);
}
