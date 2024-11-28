/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:45 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 13:15:19 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"
#include <stdlib.h>

int	count_env_nodes(t_env *env_list)
{
	t_env	*tmp;
	int	count;

	count = 0;
	tmp = env_list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char **env_list_to_strarr(t_mini *data)
{
	t_env *tmp;
	char	**env_strarr;
	int	i;

	i = 0;
	tmp = data->env_list;
	env_strarr = malloc(sizeof(char *) * count_env_nodes(data->env_list) + 1);
	if (env_strarr == NULL)
		free_data_and_exit(data, 1);
	while (tmp)
	{
		env_strarr[i] = ft_strjoin(tmp->variable, tmp->content);
		i++;
		tmp = tmp->next;
	}
	env_strarr[i] = NULL;
	return (env_strarr);
}

size_t	strarr_len(char **strarr)
{
	size_t	len;

	len = 0;
	while (strarr[len])
		len++;
	return (len);
}

char	**strarr_cpy(char **strarr)
{
	char	**cpy;
	int	i;

	i = 0;
	cpy = (char **)ft_calloc(strarr_len(strarr) + 1, sizeof(char *));
	if (cpy == NULL)
		exit (EXIT_FAILURE);
	while (strarr[i])
	{
		cpy[i] = ft_strdup(strarr[i]);
		if (cpy[i] == NULL)
		{
			free_strarr(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
