.PHONY: default coverage test clean
CFLAGS=-g -Wall -Wextra -Werror -Wpedantic -Wshadow -pedantic-errors -Wsign-conversion -O2

default: main
main: main.o
	g++ ${CFLAGS} $^ -o main
main.o: main.cpp list.h list.hpp
	g++ ${CFLAGS} -c main.cpp

test: CFLAGS=--coverage
test: testsuite
	@./testsuite
testsuite: test_main.o test_list.o
	g++ ${CFLAGS} $^ -o testsuite

coverage: CFLAGS=--coverage
coverage:  testsuite
	./testsuite
	gcov -mr test_list.cpp

test_list.o: test_list.cpp list.h list.hpp
	g++ ${CFLAGS} -c test_list.cpp

test_main.o: test_main.cpp
	g++ -O3 -c test_main.cpp

clean:
	-@rm -f testsuite
	-@rm -f *.o
	-@rm -f main
	-@rm -f *.gcov *.gcno *.gcda