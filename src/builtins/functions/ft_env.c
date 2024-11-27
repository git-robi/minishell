#include "../../../includes/mini.h"

int ft_env(t_env *envcpy)
{
    t_env *temp;
    int i = 0;

    temp = envcpy;
    if (!temp)
        return (1);
    while (temp)
    {
        if (strchr(temp->variable, '='))  
        {
            if (!temp->content)
                printf("%s\n", temp->variable);
            else
                printf("%s%s\n", temp->variable, temp->content);
        }
        temp = temp->next;
        i++;
    }
    return (0);
}


