/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:35:28 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 18:36:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static t_env	*find_env_variable(t_env *env, const char *variable)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (strcmp(temp->variable, variable) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

static int	doublepointerlenght(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	print_export_variable(t_env *temp)
{
	if (strchr(temp->variable, '=') && temp->content == NULL)
		printf("declare -x %s%s\n", temp->variable, "''");
	else if (temp->content == NULL)
		printf("declare -x %s\n", temp->variable);
	else
		printf("declare -x %s\"%s\"\n", temp->variable, temp->content);
}

void	update_or_add_env_variable(t_mini *data, char **arg, int i,
			t_content *content)
{
	t_env	*existing;

	if (separate_varcont(arg[i], content) == 0)
	{
		existing = find_env_variable(data->env, content->variable);
		if (!existing)
		{
			if (content->has_equal == 1)
				fill_env_list(&data->env, content->variable, content->content);
			else
				fill_env_list(&data->env, content->variable, NULL);
		}
		else
		{
			free(existing->content);
			if (content->has_equal == 1)
				existing->content = content->content;
			else
				existing->content = NULL;
			free(content->variable);
		}
	}
	else
		free_t_content(content);
}

int	ft_export(t_mini *data)
{
	int			i;
	int			len;
	t_env		*export_cpy;
	char		**arg;
	t_content	content;

	arg = data->parser->commands;
	if (!arg || !data)
		return (1);
	len = doublepointerlenght(arg);
	export_cpy = export_list(data->env);
	if (!export_cpy)
		return (1);
	content.variable = NULL;
	content.content = NULL;
	i = 1;
	if (strcmp("export", arg[0]) == 0)
	{
		if (len == 1)
			print_export_list(export_cpy);
		else
			process_export_variables(data, arg, len, &content);
	}
	free_env_list(export_cpy);
	return (0);
}
