/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:19 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/05 14:12:22 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/strarr_utils.h"

void	init_data(t_mini *data, char **env)
{
	data->line = NULL;
	data->envp = strarr_copy(env);
	data->lexer = NULL;
	data->parser = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_mini		data;
	
	if (argc != 1)
	{
		//print_error()
		return (2); //check correct code for error
	}
	init_data(&data, env);
	//someone is adding a welcome message, maybe we should do the same (?)
	mini_loop(&data);
	
	return (0);
}
	
	
