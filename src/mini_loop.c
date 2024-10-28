/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:34 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 10:46:46 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	mini_loop(char **env)
{
	char	*line; //line in which we store the input

	while (1)
	{

	//read input
		line = readline("minishell$ " );
	//check for empty input
		if (!line)
			//exit with right exit status
	//check if input is exit (?) maybe not necessary here
		
	//add in history
		add_history(line);

	//add tokenization, parsing, ecc...

	//free the line
		free(line);
}
