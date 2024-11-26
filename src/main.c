/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:19 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/20 11:39:39 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/mini.h"

void	init_data(t_mini *data, char **env)
{
	data->line = NULL;
	data->env = strarr_cpy(env);
	if (data->env == NULL)
		exit(EXIT_FAILURE);
	data->lexer = NULL;
	data->parser = NULL;
	data->pids = NULL;
	data->in_fd = STDIN_FILENO;
	data->env_list = env_list(env);
}

int	main(int argc, char **argv, char **env)
{
	t_mini		data;
	
	if (argc > 1 || argv[1] || !env) //what if we pass redirections
	{
		printf("No arguments accepted.\n");
		return (EXIT_SUCCESS);
	}
	init_data(&data, env);
	//someone is adding a welcome message, maybe we should do the same (?)
	mini_loop(&data);
	//free_data;	
	return (EXIT_SUCCESS);
}	
