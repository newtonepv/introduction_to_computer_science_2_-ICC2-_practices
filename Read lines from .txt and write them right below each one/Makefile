all: allantigo
	./exe

allantigo: clean create.o
	gcc readLineAndWriteIt.o -o exe

create.o:
	gcc -c readLineAndWriteIt.c

clean:
	rm *.o exe

