/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:36:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 18:15:01 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"

/*char    *mark_cont(char *content);

static int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (-1);
		i++;
	}
	return (0);
}*/

static int	ft_sintax(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isdigit(arg[i]))
			break;
		i++;
	}
	if (i > 0 && arg[i] == '\0') 
		return(invalid_arg(arg));	
	i = 0;
	while (arg[i++])
	{
		if (arg[i] == '-' && ft_strchr(arg, '=') != NULL)
		{
			if (arg[i + 1] == '=')
				invalid_arg(arg);
			else
				return (ft_export_error());
		}
	}
	if (!ft_isalpha(arg[0]) && arg[0] != '_') 
		return(invalid_arg(arg));
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return(invalid_arg(arg));
		i++;
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

int	process_export_variables(t_mini *data, char **arg,
		int len, t_content *content)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < len)
	{
		j = ft_sintax(arg[i]);
		if (j == 0)
			process_single_export_variable(data, arg, i, content);
		i++;
	}
	return (j);
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
			free(existing->content);
			existing->content = ft_strdup("");
		}
		else
		{
			free(existing->content);
			existing->content = mark_cont(content->content);
			free(content->content);
		}
	}
	free(aux);
	free(content->variable);
}
