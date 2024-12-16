/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:08:36 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 18:47:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*get_cd_path(t_mini *data);

static char	*pathishome(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i] != NULL)
	{
		if (strncmp("HOME=", env[i], 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		i++;
	}
	return (path);
}

static int	ft_error(char *path)
{
	if (access(path, F_OK) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
		return (1);
	}
	if (access(path, R_OK) == -1)
	{
		write(2, "Permission to read denied\n", 27);
		return (1);
	}
	if (access(path, X_OK) == -1)
	{
		write(2, "Permission to execute denied\n", 30);
		return (1);
	}
	return (0);
}

static char	*double_pointer_to_single(char **array)
{
	size_t	total_length;
	char	*result;
	int		i;

	total_length = 0;
	i = 0;
	while (array[i])
		total_length += strlen(array[i++]) + 1;
	result = malloc(total_length);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (array[i])
	{
		strcat(result, array[i]);
		if (array[i + 1])
			strcat(result, " ");
		i++;
	}
	return (result);
}

int	cd(t_mini *data)
{
	char	*oldpwd;
	char	*path;
	char	*newpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (-1);
	path = get_cd_path(data);
	if (!path || ft_error(path) || chdir(path) != 0)
	{
		if (!path)
			write(2, "HOME is not configured\n", 24);
		free(oldpwd);
		return (-1);
	}
	if (update_env_variable(data, oldpwd, "OLDPWD=") == -1)
		return (free(oldpwd), -1);
	free(oldpwd);
	newpwd = getcwd(NULL, 0);
	if (!newpwd || update_env_variable(data, newpwd, "PWD=") == -1)
		return (free(newpwd), -1);
	free(newpwd);
	return (0);
}

char	*get_cd_path(t_mini *data)
{
	char	**env;

	env = data->original_env;
	if (data->parser->commands && data->parser->commands[2])
	{
		write(2, "cd: too many arguments\n", 24);
		return (NULL);
	}
	if (data->parser->commands && data->parser->commands[1])
		return (data->parser->commands[1]);
	return (pathishome(env));
}
