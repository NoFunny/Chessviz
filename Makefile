all: bin/prog bin/test

bin/prog: build/main.o build/check.o build/command.o 
	gcc -Wall -Werror build/main.o build/check.o build/command.o -o bin/prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/check.o: src/check.c
	gcc -Wall -Werror -c src/check.c -o build/check.o

build/command.o: src/command.c
	gcc -Wall -Werror -c src/command.c -o build/command.o 
	
bin/test: build/command.o build/check.o  build/tests.o build/first_test.o 
	gcc -Wall build/tests.o build/command.o build/check.o build/first_test.o -o bin/test

build/test.o: test/tests.c
	gcc -Wall -c test/tests.c -o build/tests.o -Ithirdparty -Isrc

build/first_test.o: test/first_test.c
	gcc -Wall -c test/first_test.c -o build/first_test.o -Ithirdparty

test: bin/test
		bin/test

.PHONY: clean
clean:
	rm -rf build/*.o

