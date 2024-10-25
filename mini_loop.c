#include <readline/readline.h>
#include <readline/history.h>

void	mini_loop(char **env)
{
	char	*line; //line in which we store the input

	while (1)
	{

	//read input
		line = readline("minishell$ " );
	//check for empty input
		if (!line)
			//exit with right exit status
	//check if input is exit (?) maybe not necessary here
		
	//add in history
		add_history(line);

	//add tokenization, parsing, ecc...

	//free the line
		free(line);
