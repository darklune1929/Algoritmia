pilas :	pilas.o lse.o main.o
	@gcc pilas.o lse.o main.o -o pilas

main.o : main.c pilas.h
	@gcc -c main.c 

lse.o : lse.c lse.h
	@gcc -c lse.c 

pilas.o : pilas.c pilas.h
	@gcc -c pilas.c

clean : 
	@rm -f *.o pilas