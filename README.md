# pipex

A program that simulates the pipe operator (|) behavior in shell. This project is part of the 42 school curriculum.

## Description

This project involves creating a program that handles pipes between processes, similar to how the shell handles the pipe operator. It teaches about process creation, inter-process communication, file descriptors, and execution of commands in Unix-like systems.

## Features

The program implements:
- Execution of shell commands with their parameters
- Handling of input and output files
- Pipe communication between processes
- Command path resolution using environment variables
- Error handling and proper process management
- File permission management

## Getting Started

### Prerequisites
- GCC compiler
- Make
- Unix-like operating system (Linux/Mac)

### Installation
```bash
git clone https://github.com/yourusername/pipex.git
cd pipex
make
```

### Usage
```bash
./pipex file1 cmd1 cmd2 file2
```
This is equivalent to the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

Example:
```bash
./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to:
```bash
< infile ls -l | wc -l > outfile
```

## Implementation Details

The program:
1. Creates a pipe for inter-process communication
2. Forks processes for each command
3. Sets up appropriate file descriptors for input/output
4. Executes commands using execve
5. Handles command path resolution using PATH environment variable
6. Manages process synchronization and cleanup

## Error Handling
The program handles various error cases:
- Invalid number of arguments
- File access permissions
- Command not found
- Fork failures
- Pipe creation failures

## Building
The project includes a Makefile with the following rules:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and the executable
- `make re` - Rebuilds the program

## Return Value
- Returns 0 on success
- Returns appropriate error codes on failure
- Displays error messages to stderr when necessary

## Author
- Rania (radaoudi)

## License
This project is part of the 42 school curriculum. Please refer to 42's policies regarding code usage and distribution.

## Acknowledgments
- 42 school for providing the project requirements and framework
- Unix system calls and process management documentation
