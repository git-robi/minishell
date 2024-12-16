/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:35:45 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 14:36:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	update_env_variable(t_mini *data, const char *value, const char *prefix)
{
	char	*new_entry;
	char	**new_commands;
	int		i;

	new_entry = ft_strjoin(prefix, value);
	if (!new_entry)
		return (-1);
	new_commands = malloc(3 * sizeof(char *));
	if (!new_commands)
		return (free(new_entry), -1);
	new_commands[0] = "export";
	new_commands[1] = new_entry;
	new_commands[2] = NULL;
	if (data->parser->commands)
	{
		i = 0;
		while (data->parser->commands[i])
			free(data->parser->commands[i++]);
		free(data->parser->commands);
	}
	data->parser->commands = new_commands;
	ft_export(data);
	return (free(new_entry), 0);
}
