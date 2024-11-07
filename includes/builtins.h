/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:17 by codespace         #+#    #+#             */
/*   Updated: 2024/11/07 15:28:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//el student id esta mal

#ifndef BUILTINS_H
#define BUILTINS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/libft/libft.h"
void pwd();
int cd(char *path, char **env);

#endif 