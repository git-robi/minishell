
#include "../../includes/builtins.h"
#include <string.h>

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

