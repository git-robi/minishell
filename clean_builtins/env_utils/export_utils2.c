/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:36:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 18:36:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	print_export_list(t_env *export_cpy)
{
	t_env	*temp;

	temp = export_cpy;
	while (temp)
	{
		print_export_variable(temp);
		temp = temp->next;
	}
}

void	process_export_variables(t_mini *data, char **arg,
		int len, t_content *content)
{
	int	i;

	i = 1;
	while (i < len)
	{
		process_single_export_variable(data, arg, i, content);
		i++;
	}
}

void	process_single_export_variable(t_mini *data, char **arg,
		int i, t_content *content)
{
	t_env	*existing;

	if (separate_varcont(arg[i], content) == 0)
	{
		existing = find_env_variable(data->env, content->variable);
		if (!existing)
			add_new_variable(data, content);
		else
			update_existing_variable(existing, content);
	}
	else
	{
		free_t_content(content);
	}
}

void	add_new_variable(t_mini *data, t_content *content)
{
	if (content->has_equal == 1)
		fill_env_list(&data->env, content->variable, content->content);
	else
		fill_env_list(&data->env, content->variable, NULL);
}

void	update_existing_variable(t_env *existing, t_content *content)
{
	free(existing->content);
	if (content->has_equal == 1)
		existing->content = content->content;
	else
		existing->content = NULL;
	free(content->variable);
}
