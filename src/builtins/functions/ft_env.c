#include "../../../includes/mini.h"

int ft_env(t_mini *data)
{
    t_env *temp;

    temp = data->env_list;
    if (!temp)
        return (1);
    while (temp)
    {
        if (ft_strchr(temp->variable, '='))  
        {
            if (!temp->content)
                printf("%s\n", temp->variable);
            else
                printf("%s%s\n", temp->variable, temp->content);
        }
        temp = temp->next;
    }
    return (0);
}


