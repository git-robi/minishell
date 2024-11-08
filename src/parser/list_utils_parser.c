t_parser	new_node_parser(void)
{
	t_parser	*new_node;

	new_node = malloc(sizeof(t_parser));
		//add malloc check
	new_node->commands = NULL;
	new_node->redirections = NULL;
	//add builtin function
	//consider to add n of redirections
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_parser(t_parser *node, t_parser **parser_list)
{
	t_parser	*temp_node;

	temp_node = *parser_list;
	if (*parser_list == NULL)
	{
		*parser_list = new_node;
		return ;
	}
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	temp_node->next = new_node;
	new_node->prev = temp_node;
}
