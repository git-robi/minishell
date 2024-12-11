/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_env_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:48:35 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/10 13:48:38 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

char	*expand_and_replace_qm(t_mini *data, char *string, int start, char *exit_code)
{
	char	*before_var;
	char	*after_var;
	char	*tmp;

	before_var = ft_substr(string, 0, start - 1);
	if (string[start + 1] == '\0')
	{
		string = ft_strjoin(before_var, exit_code);
		data->exp_idx = (int)ft_strlen(string) - 1;
	}
	else
	{
		after_var = ft_substr(string, start + 1, ft_strlen(string) - 1);
		tmp = ft_strjoin(before_var, exit_code);
		data->exp_idx = (int)ft_strlen(tmp) - 1;
		string = ft_strjoin(tmp, after_var);
		free(after_var);
		free(tmp);
	}
	free(before_var);
	free(exit_code);
	return (string);
}

char	*handle_question_mark(t_mini *data, char *string, int start, int exit_code)
{
	if (start == 1 && string[2] == '\0')
	{
		//free(string);
		string = ft_itoa(exit_code);
		data->exp_idx = (int)ft_strlen(string) - 1;
	}
	else
		string = expand_and_replace_qm(data, string, start, ft_itoa(exit_code));
	return (string);
}

char	*unmatched_var(t_mini *data, char *string, int start, int end)
{
	char	*before_var;
	char	*after_var;

	if (start == 1 && string[end + 1] == '\0')
	{
		data->exp_idx = 0;
//		free(string);
		string = ft_strdup("\0");
	}
	else
	{
		if (start == 1)
			before_var = ft_strdup("");
		else
			before_var = ft_substr(string, 0, start - 1);
		if (string[end + 1] == '\0')
		{
			free(string);
			string = before_var;
			data->exp_idx = (int)ft_strlen(string) - 1;
		}
		else
		{
			after_var = ft_substr(string, end + 1, ft_strlen(string) - end - 1);
			string = ft_strjoin(before_var, after_var);
			data->exp_idx = (int)ft_strlen(before_var);
		}
		free(before_var);
		free(after_var);
	}
	return (string);
}
