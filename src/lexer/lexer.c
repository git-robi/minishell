/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/27 15:56:07 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"
#include <stdio.h>

int	is_double_quoted(char *str)
{
	if (str[0] == '\"' && str[ft_strlen(str) - 1] == '\"')
		return (1);
	return (0);
}

void	clean_line(char **line)
{
	char	*tmp;
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == ' ')
		{
			(*line)[i] = (*line)[ft_strlen(*line) - 1];
			(*line)[ft_strlen(*line) - 1] = ' ';
			break;
		}
		i++;
	}
	tmp = ft_strtrim(*line, " ");
	free(*line);
	*line = tmp;
}

void	delete_inside_quotes(char **line, int start, int end, char quote) 
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

void	read_token(t_mini *data)
{	
	int		i;
	int		j;
	char		*line;
	i = 0;

	line = ft_strtrim(data->line, " ");
	free(data->line);
	data->line = remove_quotes(line);
	data->line = ft_strtrim(data->line, " ");
	while (data->line[i])
	{
		while (is_whitespace(data->line[i]))
			i++;
		j = store_token(&data->line[i], data);
		if (j < 0)
			free_data_and_exit(data, EXIT_FAILURE);
		i = i + j;
	}
	remove_inside_quotes(data);
}
