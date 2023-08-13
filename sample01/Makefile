main:main.o hello.o world.o
	gcc -o main main.o hello.o world.o

main.o:main.c hello/hello.h world/world.h
	gcc -c main.c -I world

hello.o:hello/hello.c hello/hello.h
	gcc -c hello/hello.c

world.o:world/world.c world/world.h
	gcc -c world/world.c

clean:
	rm -rf main main.o hello.o world.o