all: hello_allantigo
	./hello_world_exe

hello_allantigo: hello_clean hello_create.o
	gcc hello_world.o -o hello_world_exe

hello_create.o:
	gcc -c hello_world.c

hello_clean:
	rm *.o hello_world_exe
