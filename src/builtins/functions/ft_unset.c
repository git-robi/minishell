#include "../../../includes/mini.h"

static int ft_free_from_env(t_env **head, t_env *env)
{
    if (!env)
        return (1);

    if (!env->prev)
        *head = env->next;
    else
        env->prev->next = env->next;

    if (env->next)
        env->next->prev = env->prev;

    free(env->variable);
    free(env->content);
    free(env);
    return (0);
}

static char *ft_strndup(const char *s, size_t n) 
{
    size_t len = strnlen(s, n); // Obtiene el número real de caracteres a copiar
    char *dup = (char *)malloc(len + 1); // Reservar memoria para la copia (incluye el '\0')

    if (!dup) 
        return NULL; // Retorna NULL si malloc falla

    memcpy(dup, s, len); // Copiar los caracteres de la cadena original
    dup[len] = '\0';     // Asegurarse de que la nueva cadena esté terminada en '\0'

    return dup;          // Retornar la nueva cadena duplicada
}

char *ft_withoutequal(char *arg)
{
    int i;
    char *new_var;
    i = 0;
    while (arg[i] != '=' && arg[i])
    {
        i++;
    }
    new_var = ft_strndup(arg, i);
    if (!new_var)
        return(NULL);
    return (new_var);
}


int ft_unset(t_mini *data)
{
    t_env *env_node;
    t_env *next_node;
    char **args;
    int i;

    env_node = data->env_list;
    args = data->parser->commands;

    if (!args[1]) // No hay argumentos para unset
        return 0;

    while (env_node)
    {
        next_node = env_node->next; // Guarda el siguiente nodo antes de modificar
        i = 1;
        while (args[i])
        {
            // Compara la variable hasta el '=' con el argumento actual
            if (strncmp(env_node->variable, args[i], strlen(args[i])) == 0 
                && env_node->variable[strlen(args[i])] == '=')
            {
                ft_free_from_env(&data->env_list, env_node);
                break; // Rompe el ciclo interno para evitar iterar innecesariamente
            }
            i++;
        }
        env_node = next_node; // Pasa al siguiente nodo
    }
    return 0;
}
