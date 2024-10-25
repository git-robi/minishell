
size_t	strarr_len(char **strarr)
{
	size_t	len;

	len = 0;
	while (strarr[len])
		len++;
	return (len);
}

char	**strarr_cpy(char **strarr)
{
	char	**strarr_cpy;
	int	i;

	strarr_cpy = (char **)malloc(sizeof(char *) * (strarr_len(strarr) + 1));
	if (strarr_cpy == NULL)
		exit (); //check exit code
	while (strarr[i])
	{
		strarr_cpy[i] = ft_strdup(strarr[i]);
		if (strarr_cpy[i] == NULL)
			exit (); //check exit code (again) and also discuss if we have to free in cases like this.
		i++;
	}
	strarr_cpy[i] = NULL;
	return (strarr_cpy);
}
