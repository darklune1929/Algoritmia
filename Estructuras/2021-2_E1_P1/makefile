colas :	colas.o lse.o main.o
	@gcc colas.o lse.o main.o -o colas

main.o : main.c colas.h
	@gcc -c main.c 

lse.o : lse.c lse.h
	@gcc -c lse.c 

clean : 
	@rm -f *.o colas