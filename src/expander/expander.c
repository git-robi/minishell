/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:47:32 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/10 13:47:42 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

/*void	expand_string(t_mini *data, char **string)
{
	int	i;
	int	j;
	char	*tmp;
	char	*tmp_str;
	int	single_quote;
	int	double_quote;

	single_quote = 0;
	double_quote = 0;
	i = -1;
	tmp_str = ft_strdup(*string);
	tmp = ft_strdup(*string);
	while (tmp[++i] != '\0')
	{
		if (tmp[i] == '\'' && (double_quote == 0 || double_quote % 2 == 0))
			single_quote++;
		if (tmp[i] == '\"' && (single_quote == 0 || single_quote % 2 == 0))
			double_quote++;
		if (tmp[i] == '$')
		{
			while (tmp[i] == '$')
				i++;
			if (tmp[i] == '\0' || is_whitespace(tmp[i]))
				continue ;
			if (tmp[i] == '?')
			{
				tmp_str = handle_question_mark(tmp, i, data->exit_code, &i);
			//	free(tmp);
				tmp = ft_strdup(tmp_str);
				continue ;
			}
			j = i;
			while (tmp[j] != '$' && tmp[j] != '\0' && !is_whitespace(tmp[j]) && !is_quote(tmp[j]))
				j++;
//			free(tmp_str);
			if (single_quote == 0 || single_quote % 2 == 0)
				tmp_str = expand_substring(data, tmp, i, j - 1, &i);
			free(tmp);
		}
		tmp = ft_strdup(tmp_str);
	}
//	free(tmp);
	*string = tmp_str;
}*/

char	*env_expand(t_mini *data, char **tmp, int *i, char **string)
{
	int	j;

	if ((*tmp)[*i] == '\0' || is_whitespace((*tmp)[*i]))
		return (*tmp);
	free (*string);
	if ((*tmp)[*i] == '?')
		*string = handle_question_mark(*tmp, *i, data->exit_code, i);
	else
	{
		j = *i;
		while ((*tmp)[j] && (*tmp)[j] != '$' && !is_whitespace((*tmp)[j]) && !is_quote((*tmp)[j]))
			j++;
		*string = expand_substring(data, *tmp, *i, j - 1, i);
	}
//	free(*tmp);
	*tmp = ft_strdup(*string);
	return (*tmp);
}

void	expand_string(t_mini *data, char **string)
{
	int		i;
	int		single_quote;
	int		double_quote;
	char	*tmp;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	tmp = ft_strdup(*string);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\'' && double_quote == 0)
			single_quote = !single_quote;
		else if (tmp[i] == '\"' && single_quote == 0)
			double_quote = !double_quote;
		else if (tmp[i] == '$' && single_quote == 0)
		{
			i++;
			tmp = env_expand(data, &tmp, &i, string);
		/*	i++;
			if (tmp[i] == '\0' || is_whitespace(tmp[i]))
				continue;
			if (tmp[i] == '?')
				*string = handle_question_mark(tmp, i, data->exit_code, &i);
			else
			{
                		j = i;
                		while (tmp[j] && tmp[j] != '$' && !is_whitespace(tmp[j]) && !is_quote(tmp[j]))
                    			j++;
                		*string = expand_substring(data, tmp, i, j - 1, &i);
			}
			free(tmp);
			tmp = ft_strdup(*string);*/
			continue ;
		}
		i++;
	}
	free(tmp);
}

void	expander(t_mini *data)
{
	t_parser	*tmp;
	char		**cmd_tmp;
	int			i;

	tmp = data->parser;
	while (tmp)
	{
		i = -1;
		while (tmp->commands[++i])
			expand_string(data, &tmp->commands[i]);
		cmd_tmp = strarr_cpy(tmp->commands);
		free_strarr(tmp->commands);
		tmp->commands = cmd_tmp;
		tmp = tmp->next;
	}
	clean_quotes(data);
}
