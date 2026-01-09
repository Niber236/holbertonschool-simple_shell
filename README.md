![Uploading flowchart_anglais.png…]()






# C - Simple Shell

## 📋 Description

This project involves designing a UNIX command interpreter (shell) from scratch using the C language. It is a deep dive into system calls, memory management, and process lifecycles.
*“Simplicity is the ultimate sophistication.”* – This shell replicates the basic functionality of `/bin/sh` with rigorous resource management.

## 🛠 Requirements
- C compiler (GCC recommended).
- Linux/UNIX operating system.

## ⬇️ Installation ⬇️

Clone the repository and compile the program :

- `git clone [https://github.com/d-serigba/holbertonschool-simple_shell.git](https://github.com/d-serigba/holbertonschool-simple_shell.git)`

- `cd holbertonschool-simple_shell`

- `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## 🤔 Examples of use
Interactive mode :

- `$ ./hsh`

- `($) ls -l`

- `($) exit`

Non-Interactive Mode :

- `$ echo "pwd" | ./hsh`

- `/home/user/simple_shell`

## 🚀 Features
**Interactive Mode** : Displays a `($)` prompt and waits for user commands.

**Non-Interactive Mode** : Able to read commands via a pipe (e.g., `echo "ls" | ./hsh`).

**PATH Management** : Automatically searches for executables in the environment.

**Built-in Commands** :

- `exit` : Closes the shell safely.

- `env` : Displays the current environment variables.

**Arguments** : Support for commands with multiple arguments (e.g., `ls -l /tmp`).

**Error Handling** : Precise error messages including the program name and line number.

## 📖❓Manual 

`man ./man_1_simple_shell`

## 📂 Project Structure
| File | Role/Responsibility |
| :--- | :--- |
| 📄 `main.c` | Entry point: manages the REPL loop and interactive mode. |
| 📂 `shell.h` | Library: defines structures and prototypes. |
| ⚙️ `executor.c` | Engine: orchestrates `fork()`, `execve()`, and `wait()`. |
| 🔍 `path_handler.c` | Strategist: locates commands in PATH directories. |
| 🛠️ `builtins.c` | Internal functions: implements `exit` and `env`. |
| 🧪 `parser.c` | Lexical Analyzer: Tokenizes raw user input into a clean array of executable arguments. |

Translated with DeepL.com (free version)

## 🧠 Technical concepts used
Process: Use of `fork()` to isolate command execution.

Parsing: Tokenization of user input via `strtok()`.

Memory: Dynamic management with `malloc` and `free`, ensuring no leaks.

Environment: Accessing and searching the system's `PATH`.

## 👥 Authors

- Bernis Kouzou

- Dylan Serigba

*This project was completed as part of the Holberton School curriculum.*
