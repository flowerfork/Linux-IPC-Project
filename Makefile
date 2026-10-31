CC = gcc
CFLAGS = -Wall -Wextra

all: ipc_project pipe/pipe_demo fifo/fifo_writer fifo/fifo_reader

ipc_project: main.c
	$(CC) $(CFLAGS) main.c -o ipc_project

pipe/pipe_demo: pipe/pipe_demo.c
	$(CC) $(CFLAGS) pipe/pipe_demo.c -o pipe/pipe_demo

fifo/fifo_writer: fifo/fifo_writer.c
	$(CC) $(CFLAGS) fifo/fifo_writer.c -o fifo/fifo_writer

fifo/fifo_reader: fifo/fifo_reader.c
	$(CC) $(CFLAGS) fifo/fifo_reader.c -o fifo/fifo_reader

clean:
	rm -f ipc_project
	rm -f pipe/pipe_demo
	rm -f fifo/fifo_writer
	rm -f fifo/fifo_reader
	rm -f fifo/myfifo
