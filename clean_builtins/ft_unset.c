/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:24:15 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 15:27:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

static int	ft_free_from_env(t_env **head, t_env *env)
{
	if (!env)
		return (1);
	if (!env->prev)
		*head = env->next;
	else
		env->prev->next = env->next;
	if (env->next)
		env->next->prev = env->prev;
	free(env->variable);
	free(env->content);
	free(env);
	return (0);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	len = strnlen(s, n);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

char	*ft_withoutequal(char *arg)
{
	char	*new_var;
	int		i;

	i = 0;
	while (arg[i] != '=' && arg[i])
		i++;
	new_var = ft_strndup(arg, i);
	if (!new_var)
		return (NULL);
	return (new_var);
}

int	ft_unset(t_mini *data)
{
	t_env	*env_node;
	t_env	*next_node;
	char	**args;
	int		i;

	env_node = data->env;
	args = data->parser->commands;
	if (!args[1])
		return (0);
	while (env_node)
	{
		next_node = env_node->next;
		i = 1;
		while (args[i++])
		{
			if (strncmp(env_node->variable, args[i], strlen(args[i])) == 0
				&& env_node->variable[strlen(args[i])] == '=')
			{
				ft_free_from_env(&data->env, env_node);
				break ;
			}
		}
		env_node = next_node;
	}
	return (0);
}
