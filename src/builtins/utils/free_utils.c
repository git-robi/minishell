/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:11:55 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/19 19:11:57 by rgiambon         ###   ########.fr       */
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
