all : exec

exec : lenet5.o prog.o
	gcc -o prog lenet5.o prog.o

lenet5.o : lenet5.c lenet5.h
	gcc -c lenet5.c

prog.o : prog.c lenet5.h
	gcc -c prog.c

clean :
	rm *.o *exe 