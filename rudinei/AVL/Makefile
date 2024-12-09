run: all
	./exe

all:clean item avl main
	gcc item.c avl.c main.c -o exe

item:
	gcc -c item.c

avl:
	gcc -c avl.c

main:
	gcc -c main.c

clean:
	rm *exe* *.o