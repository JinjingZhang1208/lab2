CC = gcc
CFLAGS = -Wall -g
DEPS = adjacencymatrix.h
OBJ = main.o adjacencymatrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) main