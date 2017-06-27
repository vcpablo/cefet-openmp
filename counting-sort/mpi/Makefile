SRCS= main.c

OBJS= $(SRCS:.c=.o)

BIN= $(SRCS:.c=)

CC= mpicc

%.o: %.c
	$(CC) -c $< -o $@

all: $(OBJS)
	$(CC) $^ -o $(BIN)
	chmod +x $(BIN)
	mpiexec -n 4 $(BIN)

clean:
	rm -f $(OBJS) $(BIN)
