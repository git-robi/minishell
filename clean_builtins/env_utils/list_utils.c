/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:11:07 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 17:13:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	add_last_node(t_env **env_cpy, t_env *new_node)
{
	t_env	*last_node;

	last_node = ft_last_node(*env_cpy);
	if (last_node)
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	else
		*env_cpy = new_node;
}

t_env	*ft_last_node(t_env *env_cpy)
{
	t_env	*last;

	last = NULL;
	if (!env_cpy)
		return (NULL);
	while (env_cpy)
	{
		last = env_cpy;
		env_cpy = env_cpy->next;
	}
	return (last);
}
