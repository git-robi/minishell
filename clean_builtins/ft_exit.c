/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:37:42 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 16:00:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_comands_len(char **commands)
{
	int	i;

	i = 0;
	while (commands[i] != NULL)
		i++;
	return (i);
}

int	check_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_exit(t_mini *data)
{
	int	exit_code;
	int	comands_len;

	comands_len = ft_comands_len(data->parser->commands);
	if (comands_len > 2)
		return (write(2, "exit: too many arguments\n", 25), 1);
	if (comands_len == 2 && check_number(data->parser->commands[1]))
	{
		printf("exit: %s: %s", data->parser->commands[1], NUMERICERROR);
		free_everything(data);
		exit(2);
	}
	if (comands_len == 2)
	{
		exit_code = ft_atoi(data->parser->commands[1]);
		printf("exit\n");
		free_everything(data);
		exit(exit_code);
	}
	if (comands_len == 1)
	{
		printf("exit\n");
		free_everything(data);
		exit(0);
	}
}
