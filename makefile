
#link
encoder : encoder.o
	gcc -m32 -g -Wall -o encoder encoder.o

#compile encoder.c
encoder.o : encoder.c
	gcc -m32 -g -Wall -c -o encoder.o encoder.c

#clean
clean :
	rm -f *.o encoder



