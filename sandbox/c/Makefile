all: hello_world

hello_world.o: hello_world.c
	gcc -c hello_world.c

hello_world: hello_world.o
	gcc -g -o hello_world hello_world.o
 
debug: hello_world.c
	gcc -Wall -g -o hello_world hello_world.c

clean:
	rm -rf hello_world hello_world.o hello_world.dSYM hello_world_debug.dSYM hello_world_debug
