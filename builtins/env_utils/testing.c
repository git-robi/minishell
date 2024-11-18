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

void append_node(t_env **list, const char *variable)
{
    t_env *new_node;
    t_env *last;

    new_node = malloc(sizeof(t_env));
    if (!new_node)
    {
        write(2, "Error: Memory allocation failed\n", 33);
        exit(1);
    }
    new_node->variable = strdup(variable);
    new_node->next = NULL;

    if (!*list)
        *list = new_node;
    else
    {
        last = *list;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
}
void bubble_sort_env_list(t_env **head)
{
    t_env *current;
    t_env *last = NULL;
    char *temp_variable;
    int swapped = 1;

    if (!head || !(*head))
        return;
    while (swapped)
    {
        swapped = 0; // Reinicia la bandera
        current = *head;

        while (current->next != last)
        {
            if (strcmp(current->variable, current->next->variable) > 0)
            {
                temp_variable = current->variable;
                current->variable = current->next->variable;
                current->next->variable = temp_variable;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }
}


t_env *export_list(t_env *original)
{
    t_env *copy = NULL;
    t_env *current = original;

    while (current)
    {
        append_node(&copy, current->variable);
        current = current->next;
    }
    bubble_sort_env_list(&copy);
    return copy;
}



int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_env *env_cpy;
	t_env *export_cpy;

	env_cpy = env_list(env);
	export_cpy = export_list(env_cpy);
	/*while(env_cpy)
	{
		printf("%s\n", env_cpy->variable);
		env_cpy = env_cpy->next;
	}*/
	while(export_cpy)
	{
    	printf("declare -x %s\n", export_cpy->variable);
    	export_cpy = export_cpy->next; // Debes recorrer export_cpy, no env_cpy
	}
	return(0);
}