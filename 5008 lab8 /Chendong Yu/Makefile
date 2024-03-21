CC = gcc
CFLAGS = -Wall -g
DEPS = dfs.h
OBJ = main.o dfs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) main