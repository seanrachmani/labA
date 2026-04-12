#=============================================================#
#==================actual assignment==========================#
#=============================================================#
#link
encoder : encoder.o
	gcc -m32 -g -Wall -o encoder encoder.o

#compile encoder.c
encoder.o : encoder.c
	gcc -m32 -g -Wall -c -o encoder.o encoder.c



#=============================================================#
#==================part0-skeleton files=======================#
#=============================================================#
#link
exe : add.o main.o numbers.o
	gcc -m32 -g -Wall -o exe add.o main.o numbers.o

#compile add.s
add.o : add.s
	nasm -g -f elf -w+all -o add.o add.s

#compile numbers.c
numbers.o : numbers.c
	gcc -m32 -g -Wall -c -o numbers.o numbers.c

#compile main.c
main.o : main.c
	gcc -m32 -g -Wall -c -o main.o main.c

#clean
clean :
	rm -f *.o exe my_echo encoder


#=============================================================#
#======================part0-my_echo==========================#
#=============================================================#
#link 
my_echo : my_echo.o
	gcc -m32 -g -Wall -o my_echo my_echo.o

#compile my_echo.c
my_echo.o : my_echo.c
	gcc -m32 -g -Wall -c -o my_echo.o my_echo.c


