#include "../../../includes/mini.h"

int is_there_flags(char **args) 
{
    int count = 0;
    int i = 1;
    int j;
    while (args[i]) 
    {
        j = 2;
        if (ft_strncmp(args[i], "-n", 2) == 0) 
        {
            while (args[i][j] == 'n')
                j++;
        }
        if (args[i][j] == '\0')
            count++;
        else
            break; 
        i++;
    }
    return count;
}

int ft_echo(t_mini *data, t_parser *cmd)
{
    int i;
    char **args;
    args = cmd->commands;
    int no_space;
    int flag;


	(void)data;    
    flag = is_there_flags(args);
    i = 1 + flag;
    no_space = 0;
    while (args[i])
    {
        if (no_space == 1)
            printf(" ");
        printf("%s ", args[i]);
        i++;
    }
    if (flag)
        return(0);
    printf("\n");
    return (0);
}

/*int main ()
{
    t_mini  data;
    t_parser args;
    char *frase[] = { "echo", "-nnnnnn", "hola", "-n", "xd", NULL };
    args.commands = frase;
    data.parser = &args;
    ft_echo(&data);
    return (0);
}*/
