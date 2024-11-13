/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:58:20 by codespace         #+#    #+#             */
/*   Updated: 2024/11/13 17:56:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include <string.h>

static t_env	*ft_last_node(t_env *env_cpy)
{
	t_env	*last;

	if (!env_cpy)
		return (NULL);
	while (env_cpy)
	{
		last = env_cpy;
		env_cpy  = env_cpy->next;
	}
	return (last);
}

static void fill_env_list(t_env **env_cpy, const char *variable)
{
    t_env   *new_node;
    t_env   *last_node;

    if (!env_cpy)
		return ;
	new_node = malloc(sizeof(t_env));
	if (!new_node)
	{
		write(2, "error", 6);
		exit(1);
	}
	new_node->variable = strdup(variable);
	new_node->next = NULL;
	new_node->has_value = 0;
	if (!(*env_cpy))
		*env_cpy = new_node;
	else
	{
		last_node = ft_last_node(*env_cpy);
		last_node->next = new_node;
	}
}

t_env *env_list(char **env)
{
    int i;
    char *variable;
    t_env *env_cpy;
	//check env??  
	env_cpy = NULL;
    i = 0;
    while (env && env[i]) 
    {
        variable = env[i];
        fill_env_list(&env_cpy, variable); 
        i++;
    }
    return (env_cpy);
}
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_env *env_cpy;
	env_cpy = env_list(env);
	while(env_cpy)
	{
		printf("%s\n", env_cpy->variable);
		env_cpy = env_cpy->next;
	}
	return(0);
}