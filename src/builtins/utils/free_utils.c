/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:07:54 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 15:00:26 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"

void	free_env_list(t_env *env)
{
	t_env	*tmp;
	t_env	*next;

	tmp = env;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->variable);
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
}

void	free_t_content(t_content *content)
{
	if (content)
	{
		if (content->variable)
			free(content->variable);
		if (content->content)
			free(content->content);
	}
}
