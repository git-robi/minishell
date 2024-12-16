/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:54:54 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 15:13:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	is_there_flags(char **args)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (args[i])
	{
		j = 2;
		if (strncmp(args[i], "-n", 2) == 0)
		{
			while (args[i][j] == 'n')
				j++;
		}
		if (args[i][j] == '\0')
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

int	ft_echo(t_mini *data)
{
	int		i;
	char	**args;
	int		no_space;
	int		flag;

	args = data->parser->commands;
	flag = is_there_flags(args);
	i = 1 + flag;
	no_space = 0;
	while (args[i])
	{
		if (no_space == 1)
			printf(" ");
		printf("%s", args[i]);
		i++;
	}
	if (flag)
		return (0);
	printf("\n");
	return (0);
}
