all: main import.o
	gcc -o main -Wall -Wextra -Wconversion main.o import.o
 
main: main.c import.h
	gcc -c -Wall -Wextra -Wconversion main.c
 
clean:
	rm main main.o