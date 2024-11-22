/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_exe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:12:49 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/22 12:03:24 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void	handle_redir_in(t_lexer *redirection)
{
	int	fd;

	fd = open(
}

void	handle_redir_out(t_lexer *redirection)
{
}

void	handle_append(t_lexer *redirection)
{
}

void	dispatch_redirections(t_lexer *redirection)
{
	if (redirection->type == REDIR_IN)
		handle_redir_in(redirection);
	if (redirection->type == REDIR_OUT)
		handle_redir_out(redirection);
	if (redirection->type == APPEND)
		hndle_append(redirection);
}


//in this function I have to include a error handling (check what is the behviour in casse of error)

void	redirections_exe(t_parser *cmd)
{
	t_lexer	*redirection;

	redirection = cmd->redirections;
	if (!redirection)
		return ;
	while (redirection)
	{
		dispatch_redirections(redirection);
		redirection = redirection->next;
	}
}
