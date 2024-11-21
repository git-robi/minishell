/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:11:59 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/20 11:41:44 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	executor(t_mini *data)
{
	int		commands;

	commands = count_nodes(data->parser);
	if (commands == 1)
		//call function that executes a single command
	else
	{
		//create array to store the process IDs of the child processes:
		data->pids = (int *)malloc(sizeof(int) * commands);
		if (data->pids == NULL)
			//free and exit
		execute_multiple_commands(data);
	}
}
