/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:38:18 by codespace         #+#    #+#             */
/*   Updated: 2024/12/16 18:39:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	ft_env(t_env *envcpy)
{
	t_env	*temp;
	int		i;

	i = 0;
	temp = envcpy;
	if (!temp)
		return (1);
	while (temp)
	{
		if (strchr(temp->variable, '='))
		{
			if (!temp->content)
				printf("%s\n", temp->variable);
			else
				printf("%s%s\n", temp->variable, temp->content);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}
