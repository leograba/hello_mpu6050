CC = gcc
CFLAGS ?=

hello: main.o
	$(CC) -o accel_read main.o

clean:
	rm -f *.o accel_read
