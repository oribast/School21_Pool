CCFLAGS=gcc -Wall -Werror -Wextra -std=c11
VALGRIND=\valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./spiralSquaringMatrix.out
CPP=\cppcheck --enable=all --suppress=missingIncludeSystem *.c


all: build

clean:
	rm -rf *.out

rebuild: clean build

clang:
	clang-format -n *.c
	clang-format -i *.c

cpp:
	$(CPP)

valgrind:
	$(VALGRIND)

build: groot sequence matrixRotate spiralSquaringMatrix

groot: groot.c
	$(CCFLAGS) groot.c -o groot.out

sequence: sequence.c
	$(CCFLAGS) sequence.c -o sequence.out

matrixRotate: matrixRotate.c
	$(CCFLAGS) matrixRotate.c -o matrixRotate.out

spiralSquaringMatrix: spiralSquaringMatrix.c
	$(CCFLAGS) spiralSquaringMatrix.c -o spiralSquaringMatrix.out


