# 🐚 minishell - Building a Shell from Scratch

Welcome to our minishell project - the most challenging and complex project I've tackled so far! This was an exciting journey where my teammate and I created our own version of a shell, similar to bash. Not only did we dive deep into how command-line interfaces work, but we also learned the valuable lessons of collaborative coding!

## What's This Project About?

Ever wondered how your terminal works under the hood? Well, I built one! My minishell can:
- Parse and execute commands
- Handle pipes (`|`)
- Manage redirections (`>`, `>>`, `<`, `<<`)
- Expand environment variables (`$PATH`, `$HOME`, etc.)
- Execute built-in commands
- Handle signals (ctrl-C, ctrl-D, ctrl-\\)

## 🛠Building the shell

The project is structured into key components:

1. **Lexer & Parser**:
   - Tokenize input into meaningful chunks
   - Handle quotes (single and double)
   - Parse special characters and operators
   - Create command structures for execution

2. **Command Execution**:
   - Built-in commands implementation (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
   - External command execution with proper PATH handling
   - Process creation and management
   - Exit status handling

3. **Redirection System**:
   - Input/Output redirection
   - Heredoc implementation (`<<`)
   - Append mode (`>>`)
   - Pipe handling for command chaining

4. **Environment Management**:
   - Environment variable handling
   - Variable expansion
   - Export and unset functionality
   - Path resolution

## Features

### Built-in Commands:
- `echo` with -n flag
- `cd` with relative/absolute paths
- `pwd` without options
- `export` for environment variables
- `unset` to remove variables
- `env` to display environment
- `exit` with status handling

### Shell Operations:
- `|` Pipes between commands
- `<` Input redirection
- `>` Output redirection
- `>>` Append redirection
- `<<` Heredoc functionality
- Environment variable expansion
- Exit status with `$?`
- Signal handling

## Main Challenges and Solutions

Building a shell from scratch presented several significant challenges that required careful planning and smart solutions.

### Bash Behavior Implementation
Replicating bash's behavior required deep understanding of edge cases. Complex commands like `echo "$HOME'$USER'" > outfile` needed careful handling of quotes, variables, and redirections. We developed a systematic testing approach to address this challenge. Our solution involved documenting bash's behavior for complex cases and creating a comprehensive test suite. Through careful implementation of quote and variable handling rules, we ensured our shell's output matched bash's behavior precisely.

### Command Parsing
Parsing commands like `echo "Hello 'World'" | grep Hello` involved handling nested quotes, pipes, and preserving whitespace correctly. We implemented a state machine parser as our solution. The parser tracks quote states and nested levels while handling special characters and operators. It maintains the integrity of command structure and whitespace while performing syntax validation during the parsing process.

### Process Management
Managing multiple processes and pipes required careful coordination of data flow and process lifecycles. Our solution was a structured pipeline system that coordinates process relationships and data flow. We implemented robust file descriptor management and added process synchronization checks. The system handles process failures gracefully, ensuring stable execution even in complex command chains.

### Memory Management
Preventing memory leaks while handling complex command structures and unexpected terminations was crucial. We addressed this by building a comprehensive memory tracking system. This system monitors all memory allocations and implements structured cleanup routines. It handles signal interruptions safely and ensures proper resource deallocation, maintaining stability even during unexpected program termination.

### Team Collaboration
Coordinating work on interconnected shell components required careful planning and communication. We established clear development practices by defining component interfaces upfront and implementing regular code reviews. Our development process used feature branches and followed consistent coding standards. Regular sync meetings ensured all team members were aligned on implementation details and architectural decisions.

Through these solutions, we created a robust shell that handles complex commands reliably while maintaining clean code structure. The combination of careful planning, systematic implementation, and rigorous testing resulted in a stable and efficient command-line interface.

## 🎓 What I Learned

This project was an incredible learning experience in both technical and collaborative aspects of software development.

### System Programming and Shell Internals
Developing a shell required mastering process management, file descriptors, and signal handling. Working with environment variables and understanding bash's behavior patterns gave us deep insights into shell operations and UNIX system programming concepts.

### Parser Implementation
We gained practical experience in compiler theory by implementing a command parser. This involved lexical analysis for breaking down command strings and syntax parsing to interpret command structure. The project helped us understand how programming languages process and interpret input.

### Software Architecture
Organizing a large-scale project taught us the importance of modular design and error handling. We learned to structure code for maintainability and reliability, implementing robust error handling throughout the system.

### Team Development
Working as a team improved our collaboration skills through code reviews, technical discussions, and git workflow management. We developed effective communication practices and learned to resolve conflicts constructively while maintaining code quality.
## How to Use It

```bash
# Compile the project
make

# Run the shell
./minishell

# Try some commands:
minishell$> echo "Hello World!"
minishell$> ls -l | grep ".c" > output.txt
minishell$> cat << EOF > file.txt
heredoc>
heredoc> EOF
```

## Final Thoughts

Building a shell from scratch was an amazing journey into system programming! It really opened my eyes to how much happens behind the scenes when we type commands in our terminal.

The skills I learned here - from process management to parsing - have given me a much deeper understanding of how operating systems and command-line interfaces work. Plus, it's pretty cool to use a shell that I built myself! 

---
*Built with ❤️ and lots of coffee at 42 School*
