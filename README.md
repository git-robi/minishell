# 🐚 minishell - Building a Shell from Scratch

Hey there! 👋 Welcome to our minishell project - the most challenging and complex project I've tackled so far! This was an exciting journey where my teammate and I created our own version of a shell, similar to bash. Not only did we dive deep into how command-line interfaces work, but we also learned the valuable lessons of collaborative coding!

## 🎯 What's This Project About?

Ever wondered how your terminal works under the hood? Well, I built one! My minishell can:
- 📝 Parse and execute commands
- 🔄 Handle pipes (`|`)
- ↪️ Manage redirections (`>`, `>>`, `<`, `<<`)
- 🔍 Expand environment variables (`$PATH`, `$HOME`, etc.)
- 🎯 Execute built-in commands
- 🔄 Handle signals (ctrl-C, ctrl-D, ctrl-\\)

## 🛠️ Building the shell

The project is structured into several key components:

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

## 🎨 Features

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

## 🤔 The Tricky Parts

As our most challenging project yet, minishell pushed us to our limits with numerous complex features to implement:

1. **Bash Feature Recreation**:
   - Implementing numerous bash functionalities from scratch
   - Matching bash's exact behavior in various scenarios
   - Handling complex edge cases just like bash does
   - Deep diving into bash documentation and behavior

2. **Command Parsing**:
   - Handling quotes and escape characters
   - Managing complex command chains
   - Proper tokenization of input
   - Dealing with various syntax rules

3. **Process Management**:
   - Creating and managing child processes
   - Handling multiple pipes
   - Managing file descriptors
   - Synchronizing processes correctly

4. **Memory Management**:
   - Preventing memory leaks
   - Proper cleanup of resources
   - Managing dynamic structures

5. **Collaborative Challenges**:
   - Coordinating work between team members
   - Maintaining consistent coding style
   - Managing git workflow together
   - Resolving merge conflicts
   - Making design decisions as a team

## 🎓 What I Learned

This project was an incredible learning experience that went beyond just technical skills:

1. **System Programming**:
   - Deep understanding of processes
   - File descriptor management
   - Signal handling
   - Environment management

2. **Parser Design**:
   - Lexical analysis
   - Syntax parsing
   - Abstract Syntax Tree concepts

3. **Project Structure**:
   - Large project organization
   - Code modularity
   - Error handling

4. **Collaborative Skills**:
   - Working effectively in a team
   - Code review practices
   - Technical communication
   - Conflict resolution
   - Git workflow in a team setting

5. **Shell Internals**:
   - Deep understanding of how bash works
   - Complex command interpretation
   - Shell behavior and standards

## 💡 How to Use It

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

## 🔍 Final Thoughts

Building a shell from scratch was an amazing journey into system programming! It really opened my eyes to how much happens behind the scenes when we type commands in our terminal.

The skills I learned here - from process management to parsing - have given me a much deeper understanding of how operating systems and command-line interfaces work. Plus, it's pretty cool to use a shell that I built myself! 🚀

---
*Built with ❤️ and lots of coffee at 42 School*
