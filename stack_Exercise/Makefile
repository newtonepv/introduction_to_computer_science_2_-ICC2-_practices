all: compileBalanceada compileMain
	gcc balanceada.o main.o -o exe

run:
	./exe

compileBalanceada:
	gcc -c balanceada.c 

compileMain:
	gcc -c main.c

clean:
	rm *.o exe