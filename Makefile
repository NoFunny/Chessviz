all: src

src: build/main.o build/commands.o
	gcc -Wall -Werror build/main.o build/command.o -o prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/commands.o: src/commands.c
	gcc -Wall -Werror -c src/commands.c -o build/commands.o 
	
.PHONY: clean
clean:
	rm -rf build/*.o