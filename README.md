Simple Shell Project

This is a simple shell project written in C language as part of the Hoberlton School curriculum. This project aims to 
implement a basic shell program that can run various command-line commands, similar to the popular Unix/Linux shell 
programs such as bash.

Background

A shell program is a command-line interpreter that provides users with an interface to interact with an operating system.
It takes input from the user, interprets the commands, and then executes them. The shell program acts as a middleman between
the user and the operating system, providing a convenient way to manage files, directories, and run applications.

This simple shell program has been designed to be easy to understand and modify, even for beginners.
It is written in C language, which is a popular programming language used for system programming and developing operating systems.

Usage

To use this simple shell program, follow these steps:

Open your terminal and navigate to the directory where the shell program is saved.
Compile the program by running the following command: gcc -o shell shell.c
Run the program by typing ./shell in the terminal and hitting Enter.
Once you have launched the shell program, you can run various command-line commands, such as ls, cd, pwd, etc.
You can also run your own custom commands or scripts.

Example

Here's an example of how to use this simple shell program to navigate to a directory and list its contents:

shell
Copy code
$ ./shell
> cd Documents
> ls
file1.txt file2.txt file3.txt
> pwd
/home/user/Documents
> exit
$

Conclusion

This simple shell program provides a basic understanding of how a shell program works and how to implement one in C language. 
It can be used as a starting point for more complex shell programs or as a learning tool for beginners who are interested in system programming.
