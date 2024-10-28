#include "../includes/builtins.h"

void pwd()
{
    char *cwd;
    cwd = getcwd(NULL, 0);
    if (!cwd)
        perror("getcwd() error");
    else
    {
        printf("%s\n", cwd);
        free(cwd);
    }
}

/*int main()
{
    pwd();
    return(0);
}*/