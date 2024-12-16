/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:35:55 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/16 11:10:28 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	print_err_hd(char *delim)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: ", 2);
	ft_putstr_fd("here-document at last line delimited by end-of-file", 2);
	ft_putstr_fd(" (wanted '", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
