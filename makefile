#link
exe : add.o main.o numbers.o
	gcc -m32 -g -Wall -o exe add.o main.o numbers.o

#compile add.s
add.o : add.s
	nasm -g -f elf -w+all -o add.o add.s

#compile numbers.c
numbers.o : numbers.c
	gcc -m32 -g -Wall -c -o numbers.o numbers.compile

#compile main.c
main.o : main.c
	gcc -m32 -g -Wall -o numbers.o numbers.c

#clean
clean :
	rm -f *.o exe