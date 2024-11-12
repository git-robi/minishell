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
