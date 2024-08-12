all: gerarItem.o gerarMain.o
	gcc item.o main.o -std=c99 -o exe -Wall

gerarItem.o:
	gcc -c item.c

gerarMain.o:
	gcc -c main.c

clean:
	rm *.o