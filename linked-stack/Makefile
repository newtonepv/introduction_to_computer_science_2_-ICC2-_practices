all: compile
	gcc pilha.o item.o main.o -o exe -std=c99 -Wall

run:
	./exe

compile:
	gcc -c pilha.c item.c main.c

clean:
	rm *.o exe