/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:17 by codespace         #+#    #+#             */
/*   Updated: 2024/11/20 06:22:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//el student id esta mal

#ifndef BUILTINS_H
#define BUILTINS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/libft/libft.h"
#include "lexer.h"
#include "parser.h"
#include "mini.h"

#define ERROR 1
typedef struct s_env t_env;

typedef struct s_content
{
	char *variable;
	char *content;
	int has_equal;
} t_content;

//functions
int	ft_cd(t_mini *data);
int	ft_echo(t_mini *data, t_parser *cmd);
int	ft_pwd(void);
int	ft_env(t_mini *data);
int	ft_export(t_mini *data, t_parser *cmd);

//utils 
void bubble_sort_env_list(t_env **head);
t_env *export_list(t_env *original);
int     call_builtin_function(t_mini *data, t_parser *cmd);
int     builtin_in_parent(char *cmd);

//env_list
void free_env_list(t_env **env);
int separate_varcont(char *line, t_content *content);
void fill_env_list(t_env **env_cpy, const char *variable, const char *content);
t_env *env_list(char **env);
void free_t_content(t_content *content);

#endif 
