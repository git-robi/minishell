#include "../../includes/mini.h"

void	path_error(char **commands)
{
	ft_putstr_fd(commands[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_strarr(commands);
	exit (127);
}

/*int	count_words(char **commands)
{
    int count;

    count = 0;
    for (int i = 0; commands[i]; i++) {
        char *command = commands[i];
        int in_word = 0;
        for (int j = 0; command[j]; j++) {
            if (!isspace(command[j]) && !in_word) {
                in_word = 1;
                count++;
            } else if (isspace(command[j])) {
                in_word = 0;
            }
        }
    }

    return count;
}*/

int count_words(char **commands)
{
    int count = 0;
    int i = 0;

    while (commands[i]) { // Outer loop
        char *command = commands[i];
        int j = 0;
        int in_word = 0;

        while (command[j]) { // Inner loop
            if (!isspace(command[j]) && !in_word) {
                in_word = 1;
                count++;
            } else if (isspace(command[j])) {
                in_word = 0;
            }
            j++;
        }
        i++;
    }

    return count;
}

void	replace_marker(char **commands)
{
	int	i;
	int	j;

	i = 0;
	while (commands[i])
	{
		j = 0;
		while (commands[i][j])
		{
			if (commands[i][j] == '\x03' || commands[i][j] == '\x05')
				commands[i][j] = ' ';
			j++;
		}
		i++;
	}
}

// Function to create the parsed commands array without strtok
char **make_commands_cpy(char **commands) {
    int total_words = count_words(commands);
    char **result = (char **)malloc((total_words + 1) * sizeof(char *));
    int index = 0;

    for (int i = 0; commands[i]; i++) {
        char *command = commands[i];
        int start = 0, end = 0;

        while (command[start]) {
            // Skip leading spaces
            while (command[start] && isspace(command[start])) {
                start++;
            }
            end = start;

            // Find the end of the current word
            while (command[end] && !isspace(command[end])) {
                end++;
            }

            if (end > start) {
                // Extract the word
                int word_length = end - start;
                result[index] = (char *)malloc((word_length + 1) * sizeof(char));
                strncpy(result[index], command + start, word_length);
                result[index][word_length] = '\0';
                index++;
            }
            start = end;
        }
    }

    result[index] = NULL; // Null-terminate the array
    replace_marker(result);
    return result;
}

