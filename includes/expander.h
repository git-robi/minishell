/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:46:33 by rgiambon          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

typedef struct s_quotes
{
        int     f_s;
        int     f_d;
	int	s_s;
	int	s_d;
}       t_quotes;

typedef struct s_xy
{
	int	start;
	int	end;
}	t_xy;

void	expander(t_mini *data);
void	expand_string(t_mini *data, char **string);
char	*handle_question_mark(t_mini *data, char *string, \
int start, int exit_code);
char	*expand_and_replace_qm(t_mini *data, char *string, \
int start, char *exit_code);
char	*expand_substring(t_mini *data, char *string, int start, int end);
char	*expand_var(t_mini *data, char *string, t_xy xy, char *expansion);
char	*unmatched_var(t_mini *data, char *string, int start, int end);
char	*expand_and_reassemble(t_mini *data, char *string, t_xy xy, \
char *expansion);
char	*env_expand(t_mini *data, char **tmp, char **string);
void	clean_quotes(t_mini *data);
void    clean_redirections(t_mini *data, t_parser *tmp, int *marker_count);
char	*remove_marker(t_mini *data, char *str, int marker_count);
void	replace_quotes(char *str, int *marker_count, int i);

#endif
