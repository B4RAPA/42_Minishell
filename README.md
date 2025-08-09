# 42_minishell
minishell - Project at 42 school (42 Wolfsburg)

![Bonus Completed](https://img.shields.io/badge/bonus-completed-brightgreen)

<h1 align="center">
	💻 minishell
</h1>

<p align="center">
	<b><i>A simple shell implemented in C, following the 42 project guidelines</i></b><br>
</p>

<h3 align="center">
	<a href="#️-about">About</a>
	<span> · </span>
	<a href="#️-usage">Usage</a>
	<span> · </span>
	<a href="#-what-i-learned">What I Learned</a>
</h3>

---

## 💡 About the project

> _minishell the first group project at 42 that consists of creating a simple Unix shell from scratch using the C programming language. The goal is to reproduce basic shell behavior, including command parsing, execution, environment variable management, and signal handling. This project encourages collaboration and teamwork where not only technical skill such as working on Git and Github is improved but also soft skills such as communication and team spirit. This project deepens understanding of processes, pipes, and system calls, building strong foundations for further systems programming._

#### 🚀 Bonus
- [x] All bonus features implemented (e.g., logical operators, wildcard expansion, advanced redirect handling)

For more detailed information, check the [**subject of this project**](https://github.com/jonona912/42_minishell/blob/main/minishell_subject.pdf).

## 🛠️ Usage

### Requirements

minishell is written in C and requires the **`gcc` compiler** and standard **C libraries** to build and run.

### Instructions

**1. Compile minishell**

In the project directory, run:

```shell
$ make
```

**2. Run minishell**

After compilation, launch minishell with:

```shell
$ ./minishell
```

**3. Using minishell**

- Type commands just like in bash or sh (e.g., `ls -la`, `echo hello`, `export VAR=42`).
- Use pipes, redirections, and environment variables.
- Bonus features such as logical operators and wildcards are supported.

## 📚 What I Learned

- Soft skills where team work was mostly organic with good team understanding
- Backus-Naur Form (BNF) mathematical grammar and applied it using a Recursive Descent Parser to analyze input strings by constructing a binary Abstract Syntax Tree (AST) and determining the correct order of execution. To solidify my understanding, I built a [**simple_calculator**](https://github.com/jonona912/simple_calculator) as a practical exercise before returning to work on the minishell project.
- Process creation and management (fork, execve, wait)
- Parsing and tokenization of command lines
- Signal handling (SIGINT, SIGQUIT, etc.)
- Pipes and file descriptor manipulation
- Implementing built-in shell commands (cd, export, unset, etc.)
- Advanced features: logical operators, wildcards, and more
- Robust debugging and memory management in C
