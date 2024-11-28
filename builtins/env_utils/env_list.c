
#include "../../includes/builtins.h"
#include <string.h>

t_env *env_list(char **env);
int separate_varcont(char *line, t_content *content);
void fill_env_list(t_env **env_cpy, const char *variable, const char *content);
static t_env	*ft_last_node(t_env *env_cpy);
void free_env_list(t_env *env);
void free_t_content(t_content *content);

void free_t_content(t_content *content)
{
    if (content)
    {
        free(content->variable);
        free(content->content);
    }
}

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

void free_env_list(t_env *env)
{
    t_env *tmp;

    while (env)
    {
        tmp = env;
        env = env->next;
        free(tmp->variable);
        free(tmp->content);
        free(tmp);
    }
}

int separate_varcont(char *line, t_content *content)
{
    char *equals_sign;

    equals_sign = strchr(line, '=');
    if (equals_sign) 
    {
        content->has_equal = 1;
        content->variable = strndup(line, (equals_sign - line) + 1);
        if (!content->variable)
            return (1);
        if (*(equals_sign + 1) == '\0') 
            content->content = NULL;
        else 
        {
            content->content = strdup(equals_sign + 1);
            if (!content->content) 
            {
                free(content->variable);
                return (1);
            }
        }
    } 
    else 
    {
        content->has_equal = 0;
        content->variable = strdup(line);
        if (!content->variable)
            return (1);
        content->content = NULL;
    }
    return (0);
}



void fill_env_list(t_env **env_cpy, const char *variable, const char *content)
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
    if (content)
    {
        new_node->content = strdup(content);
    }
    else
    { 
       new_node->content = NULL;
    }
	new_node->next = NULL;
    new_node->prev = NULL;
	if (!(*env_cpy))
		*env_cpy = new_node;
	else
	{
		last_node = ft_last_node(*env_cpy);
		last_node->next = new_node;
        new_node->prev = last_node;
	}
}

t_env *env_list(char **env)
{
    int i;
    char *variable;
    t_content content;
    t_env *env_cpy;

    content.variable = NULL;
    content.content = NULL;
    env_cpy = NULL;

    i = 0;
    while (env && env[i])
    {
        variable = env[i];
        if (separate_varcont(variable, &content))
        {
            free_env_list(env_cpy);
            free_t_content(&content);
            return (NULL);
        }
        fill_env_list(&env_cpy, content.variable, content.content);
        free_t_content(&content);
        i++;
    }
    return (env_cpy);
}

/*int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    t_env *env_cpy;
    t_env *export_cpy;

    env_cpy = env_list(env);
    if (!env_cpy)
        return (1);
    export_cpy = export_list(env_cpy);
    if (!export_cpy)
        return (1);
    t_env *temp = export_cpy;
    while (temp)
    {
         printf("%s%s\n", temp->variable, temp->content ? temp->content : "");
         temp = temp->next;
    }
    free_env_list(export_cpy);
    return (0);
}*/





