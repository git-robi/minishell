/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:11:28 by aprenafe          #+#    #+#             */
/*   Updated: 2024/02/16 14:33:17 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ult;

	i = 0;
	ult = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ult = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (ult);
}
