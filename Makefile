mk: main.c lib/*
	gcc -o bus_depot.o main.c lib/*.c -Wall -pedantic -ansi
run: bus_depot.o
	./bus_depot.o
debug: bus_depot.o
	gcc -o bus_depot.o main.c lib/*.c -g -Wall -pedantic -ansi && valgrind --leak-check=yes --track-origins=yes ./bus_depot.o
