/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:11:02 by rgiambon          #+#    #+#             */
/*   Updated: 2024/11/10 13:39:29 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
	strarr = NULL;
}

void	free_lexer_list(t_lexer **lexer_list)
{
	while (*lexer_list)
	{
		

void	free_data(t_mini *data, int exit_code)
{
	if (data->line != NULL)
		free(data->line);
	if (data->env != NULL)
		free_strarr(data->env);
	if (data->lexer != NULL)
		free_lexer_list(&data->tokens)
	if (data->parser != NULL)
		//function that frees parser list
	if (exit_code >= 0)
		exit (exit_code);
}
