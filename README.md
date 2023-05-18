# Simple Shell Project

This is a simple shell project written in C language as part of the Hoberlton School curriculum. This project aims to 
implement a basic shell program that can run various command-line commands, similar to the popular Unix/Linux shell 
programs such as bash.

## Background

A shell program is a command-line interpreter that provides users with an interface to interact with an operating system.
It takes input from the user, interprets the commands, and then executes them. The shell program acts as a middleman between
the user and the operating system, providing a convenient way to manage files, directories, and run applications.

This simple shell program has been designed to be easy to understand and modify, even for beginners.
It is written in C language, which is a popular programming language used for system programming and developing operating systems.

## Installation
To compile the shell, run the following command in your terminal:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
This will compile all the source files and generate an executable file named `hsh`.

## Usage
To start the shell, run the following command:
`./hsh`

You will then be presented with a prompt (`#cisfun$ `), indicating that the shell is ready to accept your commands. You can then enter commands just as you would in a regular terminal.

Here are some examples of commands you can run:
- $ ls
- $ pwd
- $ echo "Hello, world!"
- $ cd /path/to/directory
- $ exit

## Conclusion

This simple shell program provides a basic understanding of how a shell program works and how to implement one in C language. 
It can be used as a starting point for more complex shell programs or as a learning tool for beginners who are interested in system programming.
