#include "../../../includes/mini.h"

int	builtin_in_parent(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset"))
	{
		return (1);
	}
	return (0);
}

int	call_builtin_function(t_mini *data, t_parser *cmd)
{
	if (!ft_strcmp(cmd->commands[0], "cd"))
		return (ft_cd(data));
	if (!ft_strcmp(cmd->commands[0], "echo"))
		return (ft_echo(data, cmd));
	if (!ft_strcmp(cmd->commands[0], "env"))
		return (ft_env(data));
//	if (!ft_strcmp(cmd->commands[0], "exit"))
//		return (ft_exit());
	if (!ft_strcmp(cmd->commands[0], "export"))
		return (ft_export(data, cmd));
	if (!ft_strcmp(cmd->commands[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->commands[0], "unset"))
		return (ft_unset(data));
	return (0);
}
