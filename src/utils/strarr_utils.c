/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:45 by rgiambon          #+#    #+#             */
/*   Updated: 2024/10/28 14:31:28 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_utils.h"
#include "../../include/strarr_utils.h"

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

	cpy = (char **)malloc(sizeof(char *) * (strarr_len(strarr) + 1));
	if (cpy == NULL)
		exit (); //check exit code
	while (strarr[i])
	{
		cpy[i] = ft_strdup(strarr[i]);
		if (cpy[i] == NULL)
			exit (); //check exit code (again) and also discuss if we have to free in cases like this.
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
