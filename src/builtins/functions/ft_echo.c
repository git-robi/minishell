/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:24:16 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/16 11:24:20 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"

int	is_there_flag(char **args)
{
	int	j;

	if (args[1])
	{
		if (!ft_strncmp(args[1], "-n", 2))
		{
			j = 2;
			while (args[1][j] == 'n')
				j++;
			if (args[1][j] == '\0')
				return (1);
		}
	}
	return (0);
}

int	ft_echo(t_mini *data, t_parser *cmd)
{
	int		i;
	char	**args;

	(void)data;
	args = cmd->commands;
	i = 1;
	if (args[i] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (is_there_flag(args))
		i++;
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
	}
	if (!is_there_flag(args))
		printf("\n");
	return (0);
}
