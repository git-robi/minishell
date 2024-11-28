/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:09:19 by codespace         #+#    #+#             */
/*   Updated: 2024/11/28 04:08:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
static t_env *find_env_variable(t_env *env, const char *variable)
{
    t_env *temp = env;

    while (temp)
    {
        if (strcmp(temp->variable, variable) == 0)
            return temp;  // La variable ya existe
        temp = temp->next;
    }
    return NULL;  // No se encontró
}
static int doublepointerlenght(char **line)
{
    int i;
    
    i = 0;
    while (line[i])
        i++;
    return (i);    
}
int ft_export(t_mini *data)
{
    int len;
    int i;
    t_env *export_cpy;
    t_content content;
    char **arg;
    arg = data->parser->commands;
    i = 1;
    content.variable = NULL;
    content.content = NULL;

    if (!arg || !data)
        return (1);

    len = doublepointerlenght(arg);
    export_cpy = export_list(data->env);
    if (!export_cpy)
        return (1);

    if (strcmp("export", arg[0]) == 0)
    {
        if (len == 1)
        {
            while (export_cpy)
            {
                if (strchr(export_cpy->variable, '=') && export_cpy->content == NULL)
                    printf("declare -x %s%s\n", export_cpy->variable, "''");
                else if (export_cpy->content == NULL)
                    printf("declare -x %s\n", export_cpy->variable);
                else
                    printf("declare -x %s\"%s\"\n", export_cpy->variable, export_cpy->content);   
                export_cpy = export_cpy->next;
            }
        }
        else
        {
            while (i < len)
            {
                if (separate_varcont(arg[i], &content) == 0)
                {
                    t_env *existing = find_env_variable(data->env, content.variable);
                    if (!existing)
                    {
                        // Si no existe, agregarla
                        if (content.has_equal == 1)
                            fill_env_list(&data->env, content.variable, content.content);
                        else
                            fill_env_list(&data->env, content.variable, NULL);
                    }

                    free(content.variable);
                    free(content.content); 
                }
                else
                {
                    free(content.variable);
                    free(content.content);
                    return 1;
                }
                i++;
            }
        }
    }
    return (0);
}


int main() 
{
    t_mini mini;
    
    t_parser parser;
    char *line[] = { "export", "hola=bomboclat=", "adios=haolo", "xd=holsdgs", "dz", NULL };
    parser.commands = line;
    mini.parser = &parser;

    
    t_env *env = NULL;
    fill_env_list(&env, "USER=", "john_doe");
    fill_env_list(&env, "PATH=", "/usr/bin:/bin");
    fill_env_list(&env, "HOME=", "/home/john");
    mini.env = env;
    
    ft_export(&mini);

    char *line2[] = { "export", NULL };
    parser.commands = line2;
    ft_export(&mini);
    
    if (ft_env(env) == 1)
        return(1);
    
    char *line3[] = { "unset", "xd", NULL };
    parser.commands = line3;
    ft_unset(&mini);

    char *line4[] = { "export", NULL };
    parser.commands = line4;
    ft_export(&mini);
    
    char *line5[] = { "exit", NULL };
    parser.commands = line5;

    ft_exit(&mini);

    return 0;
}
