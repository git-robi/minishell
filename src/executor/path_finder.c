/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:09:37 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/23 12:51:41 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/mini.h"

char	*path_checker(char **all_path, char *cmd)
{
	char	*path;
	int		i;
	char	*path_to_check;

	i = 0;
	while (all_path[i] != NULL)
	{
		path_to_check = all_path[i];
		path = malloc(ft_strlen(path_to_check) + ft_strlen(cmd) + 2);
		if (path == NULL)
			return (NULL);
		ft_strlcpy(path, path_to_check, 100000);
		ft_strlcat(path, "/", 10000);
		ft_strlcat(path, cmd, 100000);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	return (NULL);
}

char	*find_path_string(char **env)
{
	int		i;
	char	*path_str;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr((const char *)env[i], "PATH=", 5) != 0)
		{
			path_str = env[i] + 5;
			return (path_str);
		}
		i++;
	}
	return (NULL);
}

char	*path_finder(char *cmd, char **env)
{
	char	*path_str;
	char	**all_path;
	char	*right_path;

	path_str = find_path_string(env);
	if (path_str == NULL)
		return (NULL);
	all_path = ft_split(path_str, ':');
	right_path = path_checker(all_path, cmd);
	if (right_path != NULL)
		return (right_path);
	free_strarr(all_path);
	return (NULL);
}
