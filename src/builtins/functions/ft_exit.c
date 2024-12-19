/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:37:42 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 15:02:00 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"
#include <limits.h>  // Para LLONG_MAX
#include <errno.h> 

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
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	return (0);
}

static long long ft_strtoll(const char *str) 
{
    long long result = 0;
    int digit;
    int sign = 1;

    if (*str == '-') 
	{
        sign = -1;
        str++;
    } 
	else if (*str == '+') 
        str++;
    while (*str) 
	{
        digit = *str - '0'; 

        if (digit < 0 || digit > 9) 
            break;

        if (result > (LLONG_MAX - digit) / 10) 
		{
            errno = ERANGE;
            result = LLONG_MAX;
            break;
        }
        result = result * 10 + digit;
        str++;
    }
    result *= sign;
    return result;
}


static long long safe_atoi(char *str) 
{
    long long result;
	
	result = ft_strtoll(str);
    if (result == LLONG_MAX && errno == ERANGE) 
        return LLONG_MAX;
    return result;
}

int ft_exit(t_mini *data, t_parser *node) 
{
    long long exit_code;
    int comands_len;

    if (node->prev)
        return (0);

    comands_len = ft_comands_len(data->parser->commands);
    if (comands_len > 2) 
        return (write(2, "exit: too many arguments\n", 25), 1);
    if (comands_len == 2 && check_number(data->parser->commands[1])) 
    {
        printf("exit: %s: %s", data->parser->commands[1], NUMERICERROR);
        free_data_and_exit(data, 2);
    }
    if (comands_len == 2)
    {
        exit_code = safe_atoi(data->parser->commands[1]);
        if (exit_code == LLONG_MAX) 
        {
            printf("exit: %s: value too large\n", data->parser->commands[1]);
            free_data_and_exit(data, 2);
        }
        if (exit_code < 0 || exit_code > 255) 
            exit_code = exit_code % 256;
        printf("exit\n");
        free_data_and_exit(data, (int)exit_code);
    }
    if (comands_len == 1) 
    {
        printf("exit\n");
        free_data_and_exit(data, 0);
    }
    return (0);
}
