#ifndef EXPANDER_H
# define EXPANDER_H

typedef struct s_xy
{
	int	start;
	int	end;
}	t_xy;

void    expander(t_mini *data);
void    expand_string(t_mini *data, char **string);
char    *handle_question_mark(t_mini *data, char *string, int start, int exit_code);
char    *expand_and_replace_qm(t_mini *data, char *string, int start, char *exit_code);
char    *expand_substring(t_mini *data, char *string, int start, int end);
char    *expand_var(t_mini *data, char *string, t_xy xy, char *expansion);
char	*unmatched_var(t_mini *data, char *string, int start, int end);
char    *expand_and_reassemble(t_mini *data, char *string, t_xy xy, char *expansion);
char    *env_expand(t_mini *data, char **tmp, char **string);

//new quotes

void    clean_quotes(t_mini *data);
char    *remove_marker(char *str, int marker_count);
void	replace_quotes(char *str, int *marker_count, int i);

#endif
