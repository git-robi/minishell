#ifndef EXECUTOR_H
#define EXECUTOR_H

//executor file
void	executor(t_mini *data);
void	one_command(t_mini *data);
void	execute_command(t_mini *data, t_parser *cmd);

//heredoc
void	check_heredoc(t_mini *data, t_parser *cmd);
void	handle_heredoc(t_mini *data, t_parser **cmd, t_lexer **heredoc);
char *new_heredoc_name(void);
int	make_heredoc(t_mini *data, t_parser **cmd, char *delimiter);
void	handle_quotes_heredoc(t_parser **cmd, t_lexer **heredoc);

//multiple commands
void	multiple_commands(t_mini *data);
void	wait_for_processes(t_mini **data);
void	update_in_fd(t_mini **data, t_parser *cmd, int pipes_ends[2]);
void	make_process(t_mini **data, t_parser *cmd, int pipes_ends[2]);
void	redirect_in_out(t_mini  **data, t_parser *cmd, int pipes_ends[2]);

//redirections
int     redirections(t_parser *cmd);
int     dispatch_redirections(t_lexer *redirection, t_parser *cmd);
int	check_fd(int fd, int type);

//path finder
char	*path_finder(char *cmd, char **env);
char	*find_path_string(char **env);
char	*path_checker(char **all_path, char *cmd);

#endif
