#include "../../includes/mini.h"
//acces

static char *pathishome(char **env) {
    int i = 0;
    char *path = NULL;
    while (env[i] != NULL) {
        if (strncmp("HOME=", env[i], 5) == 0) {
            path = env[i] + 5;  // Skip "HOME=" part
            break;
        }
        i++;
    }
    return path;
}

static int ft_error(char *path) {
    if (access(path, F_OK) == -1) {
        printf("cd: no such file or directory: %s\n", path);
        return 1;
    }
    if (access(path, R_OK) == -1) {
        write(2, "Permission to read denied\n", 27);
        return 1;
    }
    if (access(path, X_OK) == -1) {
        write(2, "Permission to execute denied\n", 30);
        return 1;
    }
    return 0;
}

/*static char *double_pointer_to_single(char **array) {
    size_t total_length = 0;
    char *result;
    int i = 0;

    while (array[i]) {
        total_length += strlen(array[i++]) + 1;
    }

    result = malloc(total_length);
    if (!result) return NULL;

    result[0] = '\0';
    i = 0;
    while (array[i]) {
        strcat(result, array[i]);
        if (array[i + 1]) strcat(result, " ");
        i++;
    }
    return result;
}*/

int cd(t_mini *data) {
//    char **env = data->original_env;
    char *path = NULL;

    if (data->parser->commands && data->parser->commands[1]) 
    {
        path = data->parser->commands[1];
    }

    if (data->parser->commands && !data->parser->commands[1]) 
    {
        path = pathishome(data->env);
    }

    if (!path) {
        write(2, "HOME is not configured\n", 24);
        return -1;
    }

    if (ft_error(path) == 1) 
        return -1;
    if (chdir(path) != 0) 
    {
        write(2, "chdir failed\n", 13);
        return -1;
    }
    return 0;
}

/*int main() {
    char *env[] = { "HOME=/home/codespace", NULL };
    char *commands[] = { "cd", "..", NULL };

    t_parser parser = { commands };
    t_mini data;
    data.original_env = env;
    data.parser = &parser;

    // Llamamos a la función cd
    if (cd(&data) == 0) {
        printf("Directory changed successfully.\n");
    }
    pwd(&data);
    return 0;
}*/
