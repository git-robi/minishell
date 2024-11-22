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

int	check_fd(int fd, int type)
{
	
	//what about using perror instead of putstr_fd????

	if (fd < 0)
	{
		if (type == REDIR_IN || type == HERE_DOC)
			ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
		else
			ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	dispatch_redirections(t_lexer *redirection, t_parser *cmd)
{
	int	fd;

	if (redirection->type == REDIR_IN)
		fd = open(redirection->token, O_RDONLY);
	if (redirection->type == HERE_DOC)
		fd = open(cmd->heredoc_name, O_RDONLY);
	if (redirection->type == REDIR_OUT)
		fd = open(redirection->token, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (redirection->type == APPEND)
		fd = open(redirection->token ,O_CREAT | O_RDWR | O_APPEND, 0644);
	return (check_fd(fd, redirection->type));
}


//in this function I have to include a error handling (check what is the behviour in casse of error)

int	redirections(t_parser *cmd)
{
	t_lexer	*redirection;

	redirection = cmd->redirections;
	if (!redirection)
		return ;
	while (redirection)
	{
		if (dispatch_redirections(redirection, cmd))
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}
