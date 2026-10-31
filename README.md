# Linux IPC Project

## Project Title

Inter-Process Communication Mechanisms in Linux

## 1. Objective

The objective of this project is to demonstrate communication between processes in Linux using:

- Anonymous Pipes
- Named Pipes (FIFO)

The project demonstrates process creation, inter-process communication, message transfer, and synchronization using Linux system calls.

## 2. Technologies Used

- C Programming
- Ubuntu Linux
- GCC Compiler
- Linux System Calls
- Makefile

## 3. IPC Mechanisms Implemented

### A. Anonymous Pipe

The anonymous pipe is used for communication between a parent process and a child process.

The parent process creates a pipe and uses `fork()` to create the child process.

The parent writes a message into the pipe and the child reads the message.

Flow:

Parent Process
      |
      | write()
      v
    Pipe
      |
      | read()
      v
Child Process

### B. Named Pipe (FIFO)

A FIFO is used for communication between independent processes.

The FIFO writer sends a message through the named pipe and the FIFO reader receives it.

Flow:

FIFO Writer
      |
      | write()
      v
    myfifo
      |
      | read()
      v
FIFO Reader

## 4. Project Structure

linux-ipc-project/

├── main.c
├── Makefile
├── README.md
│
├── pipe/
│   ├── pipe_demo.c
│   └── pipe_demo
│
└── fifo/
    ├── fifo_writer.c
    ├── fifo_writer
    ├── fifo_reader.c
    └── fifo_reader

## 5. Compilation

The complete project can be compiled using:

make

To remove generated executable files:

make clean

## 6. Running the Main Program

Run:

./ipc_project

The menu provides:

1. Pipe Communication
2. FIFO Communication
3. Exit

## 7. Running the Pipe Program

Select option 1 from the main menu.

Enter a message.

The parent process sends the message through the pipe and the child process receives it.

## 8. Running the FIFO Program

Open Terminal 1:

cd ~/linux-ipc-project

./fifo/fifo_reader

Open Terminal 2:

cd ~/linux-ipc-project

./fifo/fifo_writer

Enter a message in the writer terminal.

The reader receives the message through the FIFO.

## 9. System Calls Used

### Pipe Module

- pipe()
- fork()
- read()
- write()
- close()

### FIFO Module

- mkfifo()
- open()
- read()
- write()
- close()
- unlink()

## 10. Testing

### Pipe Test

Input:

Hello from ipc proj

Expected Result:

The parent process sends the message and the child process receives the same message.

### FIFO Test

Input:

helloo

Expected Result:

The FIFO writer sends the message and the FIFO reader receives it.

## 11. Conclusion

The project demonstrates two Linux inter-process communication mechanisms.

Anonymous pipes are demonstrated using parent-child processes, while named pipes are demonstrated using independent writer and reader processes.

The project also demonstrates compilation and build automation using GCC and Makefile.
