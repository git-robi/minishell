/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:48:36 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/05 14:01:59 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
#define MINI_H

#include "lexer.h"
#include "parser.h"

typedef struct s_mini
{
	char		*line;
	char		**env;
	t_lexer		*lexer;
	t_parser	*parser;
}	t_mini;

#endif
