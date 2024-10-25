int	main(int argc, char **argv, char **env)
{
	char	**env;

	//arg n check
	if (argc != 1)
	{
		//print_error()
		return (2); //check correct code for error
	}
	//variables copy
	env = strarr_copy(env);
	//someone is adding a welcome message, maybe we should do the same (?)
	//minishell loop
	mini_loop(env);
	
	return (0);
}
	
	
