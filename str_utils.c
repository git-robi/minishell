size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;
	int		i;

	size = ft_strlen(s) + 1;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
