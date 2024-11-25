/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:58:20 by codespace         #+#    #+#             */
/*   Updated: 2024/11/22 13:05:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void bubble_sort_env_list(t_env **head) 
{
    t_env *current;
    t_env *last = NULL;
    char *temp_variable;
    char *temp_content;
    int temp_export;
    int swapped = 1;

    if (!head || !*head)
        return;

    while (swapped) {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (strcmp(current->variable, current->next->variable) > 0) {
                // Intercambiar variables
                temp_variable = current->variable;
                temp_content = current->content;

                current->variable = current->next->variable;
                current->content = current->next->content;

                current->next->variable = temp_variable;
                current->next->content = temp_content;
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
        fill_env_list(&copy, current->variable, current->content);
        current = current->next;
    }
    bubble_sort_env_list(&copy);
    return copy;
}