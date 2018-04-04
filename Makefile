all: prog

prog: build/main.o build/command.o
	gcc -Wall -Werror build/main.o build/command.o -o prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/command.o: src/command.c
	gcc -Wall -Werror -c src/command.c -o build/command.o 
	
.PHONY: clean
clean:
	rm -rf build/*.o