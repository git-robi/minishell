#include "../includes/builtins.h"
int is_there_flags(char **args)
{
    int i;
    int count;

    count = 0;
    i = 1;
    
    if (strcmp(args[i], "-n") == 0)
    {
        while (strcmp(args[i], "-n") == 0)
        {
            i++;
            count++;
        }
            return (count);
    }
    return (0);
}
int ft_echo(t_mini *data)
{
    int i;
    char **args;
    args = data->parser->commands;
    int no_space;
    int flag;

    i = 1;
    flag = 0;
    no_space = 0;
    flag = is_there_flags(args);
    //printf("%d", flag);
    args += flag;
    while (args[i])
    {
        if (no_space == 1)
            printf(" ");
        printf("%s", args[i]);
        i++;
    }
    if (flag)
        return(0);
    printf("\n");
    return (0);
}

int main ()
{
    t_mini  data;
    t_parser args;
    char *frase[] = { "echo", "-n", "-n", "hola ", "que tal", NULL };
    args.commands = frase;
    data.parser = &args;
    ft_echo(&data);
    return (0);
}