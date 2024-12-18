/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:36:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 14:59:56 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"

static int ft_isnumber(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return(-1);
		i++;
	}
	return (0);
}

static int ft_sintax(char *arg)
{
	int	i;

	i = 0;
	if (ft_isnumber(arg) && arg[i] != '=')
	{
		while (arg[i] && arg[i] != '=')
		{
			if (arg[i] == '-' && ft_strchr(arg, '=') != NULL)
			{
				if (arg[i + 1] == '=')
					invalid_arg(arg);
				else
					ft_export_error();
				return (-1);
			}
			i++;
		}
	}
	else	
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		return (-1);
	}
	return (0);
}

void	print_export_list(t_env *export_cpy)
{
	t_env	*temp;

	temp = export_cpy;
	while (temp)
	{
		print_export_variable(temp);
		temp = temp->next;
	}
}

void	process_export_variables(t_mini *data, char **arg,
		int len, t_content *content)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ft_sintax(arg[i]) == 0)
			process_single_export_variable(data, arg, i, content);
		i++;
	}
}

void	process_single_export_variable(t_mini *data, char **arg,
		int i, t_content *content)
{
	t_env	*existing;

	if (separate_varcont(arg[i], content) == 0)
	{
		existing = find_env_variable(data->env_list, content->variable);
		if (!existing)
		{
			add_new_variable(data, content);
			free_t_content(content);
		}
		else
			update_existing_variable(existing, content);
	}
}

void	add_new_variable(t_mini *data, t_content *content)
{
	if (content->has_equal == 1)
		fill_env_list(&data->env_list, content->variable, content->content);
	else
		fill_env_list(&data->env_list, content->variable, NULL);
}

void	update_existing_variable(t_env *existing, t_content *content)
{
	char	*aux;

	aux = ft_strdup(existing->variable);
	if (!ft_strchr(existing->variable, '=') && content->has_equal == 1)
	{
		free(existing->variable);
		existing->variable = ft_strjoin(aux, "=");
	}

	if (content->has_equal == 1)
	{
		if (!content->content)
		{
			existing->content = ft_strdup("");
		}
		else
		{
			free(existing->content);
			existing->content = content->content;
		}
	}
	free(aux);
	free(content->variable);
}
