all: bin/prog bin/test

bin/prog: build/main.o build/check.o build/commands.o 
	gcc -Wall -Werror build/main.o build/check.o build/commands.o -o prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/check.o: src/check.c
	gcc -Wall -Werror -c src/check.c -o build/check.o

build/commands.o: src/commands.c
	gcc -Wall -Werror -c src/commands.c -o build/commands.o 

bin/test: build/commands.o build/check.o  build/test.o build/first_test.o 
	gcc -Wall build/test.o build/commands.o build/check.o build/first_test.o -o bin/test

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/first_test.o: test/first_test.c
	gcc -Wall -c test/first_test.c -o build/first_test.o -Ithirdparty

test: bin/test
	bin/test

.PHONY: clean
clean:
	rm -rf build/*.o