/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:10 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/16 11:25:14 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mini.h"

int	ft_env(t_mini *data)
{
	t_env	*temp;

	temp = data->env_list;
	if (!temp)
		return (1);
	while (temp)
	{
		if (ft_strchr(temp->variable, '='))
		{
			if (!temp->content)
				printf("%s\n", temp->variable);
			else
				printf("%s%s\n", temp->variable, temp->content);
		}
		temp = temp->next;
	}
	return (0);
}
