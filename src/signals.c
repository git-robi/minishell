#include "../includes/mini.h"

int	event(void)
{
	return (EXIT_SUCCESS);
}


void	handle_sigint(int s)
{
	(void)s;
	exit_status = 2;
	rl_done = 1;
}

void	init_signals(void)
{
	struct sigaction	sa;

	rl_event_hook = event;
	sa.sa_flags = 0; 
	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
