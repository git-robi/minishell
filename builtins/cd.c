#include "../includes/builtins.h"

void cd(char *path)
{
    if (chdir(path) != 0)
    {
        //mirar errores
        perror("chdir fail");
    }
}
int main()
{
    cd("../");
    pwd();
    return(0);
}