/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:19 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 10:45:41 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/strarr_utils.h"

int	main(int argc, char **argv, char **env)
{
	char	**env;

	//arg n check
	if (argc != 1)
	{
		//print_error()
		return (2); //check correct code for error
	}
	//variables copy
	env = strarr_copy(env);
	//someone is adding a welcome message, maybe we should do the same (?)
	//minishell loop
	mini_loop(env);
	
	return (0);
}
	
	
