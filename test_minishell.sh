#!/usr/bin/env bash

test_echo_user() {
    # Step 1: Compile the minishell program
    make

    # Step 2 & 3: Run the minishell, feed "echo $USER" then "exit" to close it.
    # Capture all output, then filter only the line with the actual value.
    # The output is expected to look like:
    # minishell$ echo $USER
    # nemo
    # minishell$ exit
    #
    # By using sed -n '2p', we print only the second line of the output,
    # which should be the line containing "nemo".
    output=$(echo -e "echo \$USER\nexit" | ./minishell 2>/dev/null | sed -n '2p')

    expected="nemo"
    if [ "$output" = "$expected" ]; then
        echo "test_echo_user passed"
    else
        echo "test_echo_user failed: expected '$expected' but got '$output'"
    fi
}

# Call the test function
test_echo_user

