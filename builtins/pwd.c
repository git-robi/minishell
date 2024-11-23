#include "../includes/builtins.h"

int pwd(t_mini *data)
{
    (void)data;
    char *cwd;
    cwd = getcwd(NULL, 0);
    if (!cwd)
    {
        perror("getcwd() error");
        return (2);
    }
    printf("%s\n", cwd);
    free(cwd);
    return (0);
}

/*int main()
{
    pwd();
    return(0);
}*/