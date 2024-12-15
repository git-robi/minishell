/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:42:18 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/10 13:42:21 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

#define MARKER '\x01'

void	replace_and_reset(char *str, int *marker_count, int *first, int *second)
{
	str[*first] = MARKER;
	str[*second] = MARKER;
	*marker_count += 2;
	*first = -1;
	*second = -1;
}

void	replace_quotes(char *str, int *marker_count, int i)
{
	int	first_double;
	int	second_double;
	int	first_single;
	int	second_single;

	first_double = -1;
	second_double = -1;
	first_single = -1;
	second_single = -1;
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
			replace_and_reset(str, marker_count, &first_single, &second_single);
		else if (first_double != -1 && second_double != -1)
			replace_and_reset(str, marker_count, &first_double, &second_double);
		i++;
	}
}

char	*remove_marker(char *str, int marker_count)
{
	char	*new_string;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (marker_count == 0)
		return (str);
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

void	clean_redirections(t_parser *tmp, int *marker_count)
{
	t_lexer	*redir;

	redir = tmp->redirections;
	while (redir)
	{
		if (redir->type != HERE_DOC)
		{
			*marker_count = 0;
			replace_quotes(redir->token, marker_count, 0);
			if (*marker_count > 0)
				redir->token = remove_marker(redir->token, *marker_count);
		}
		redir = redir->next;
	}
}

void	clean_quotes(t_mini *data)
{
	int			i;
	t_parser	*tmp;
	int			marker_count;

	tmp = data->parser;
	while (tmp)
	{
		i = 0;
		while (tmp->commands && tmp->commands[i])
		{
			marker_count = 0;
			replace_quotes(tmp->commands[i], &marker_count, 0);
			if (marker_count > 0)
				tmp->commands[i] = remove_marker(tmp->commands[i], marker_count);
			i++;
		}
		clean_redirections(tmp, &marker_count);
		tmp = tmp->next;
	}
}
