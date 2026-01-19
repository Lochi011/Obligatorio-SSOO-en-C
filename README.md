# 🐚 MiniSH: A Custom Linux Shell Implementation in C

![C](https://img.shields.io/badge/C-Standard-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-SysCalls-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Build](https://img.shields.io/badge/Build-Makefile-4EAA25?style=for-the-badge)

**Course:** Operating Systems
**Focus:** Process management, system calls, and low-level C programming.

---

## 📖 Project Overview
**MiniSH** is a functional command-line interpreter (shell) built from scratch in C for Linux systems.

The project demonstrates a deep understanding of how an operating system manages processes and coordinates resource execution. It parses user input, handles built-in commands, and executes external programs using standard POSIX system calls.

### 🧠 Core Engineering Concepts
* **Process Management:** Utilizing `fork()`, `execvp()`, and `waitpid()` to spawn and manage child processes for command execution.
* **Signal Handling:** Implementing handlers for signals like `SIGINT` (Ctrl+C) to ensure the shell itself isn't terminated incorrectly.
* **Memory Management:** Dynamic allocation for parsing command arguments and environment variables.
* **I/O & File Descriptors:** Managing standard input/output streams.

---

## ✨ Key Features

* **Command Execution:** Runs standard Linux programs (e.g., `ls`, `grep`, `whoami`).
* **Built-in Commands:** Custom implementations of internal shell commands that manage the shell's state:
    * `cd`: Change directory using the `chdir()` system call.
    * `exit`: Terminate the shell session gracefully.
    * `help`: Display usage information.
* **Argument Parsing:** Tokenizes command lines into executable arguments.

---

## 🛠️ Tech Stack & Tools

| Component | Technology | Usage |
| :--- | :--- | :--- |
| **Language** | C (C99/C11) | Core logic and system calls. |
| **OS Environment** | Linux | Target deployment environment. |
| **Build System** | GNU Make | Automated compilation. |
| **Debugging** | GDB / Valgrind | Memory leak detection and debugging. |

---

## ⚡ How to Compile & Run

This project includes a `Makefile` for easy compilation.

```bash
# 1. Clone repository
git clone [https://github.com/Lochi011/Obligatorio-SSOO-en-C.git](https://github.com/Lochi011/Obligatorio-SSOO-en-C.git)
cd Obligatorio-SSOO-en-C

# 2. Compile the project
make

# 3. Run the shell
./minish
```
## 👤 Author

**Santiago Lozano**
*Computer Engineering Student*

* **Focus:** System programming and low-level architecture.
* **Contact:** [Santiago Lozano](https://www.linkedin.com/in/santiago-lozano-81171624b/)
