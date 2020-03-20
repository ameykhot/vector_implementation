CC=gcc

all : run checkmem clean

compile: vector.c vector.h list.c list.h profile.c profile.h data.h program5.c
	$(CC) -g program5.c -o program5
run:compile
	./program5
checkmem:program5
	valgrind ./program5
clean:
	rm -rf *.o program5
