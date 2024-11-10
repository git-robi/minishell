/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 12:50:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	mini_loop(t_mini *data)
{
	while (1)
	{
		data->line = readline("minishell$ " );
		if (!data->line)
		{
			ft_putstr_fd("exit\n");
			exit (EXIT_SUCCESS);
		}
		add_history(data->line);
	//handle quotes here (?)
		read_token(&data);
		parser(&data);
		free(data->line);
}
