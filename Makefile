FLAGS=-Wall -Wextra -Werror -std=c11 
LFLAGS=-lcheck -lm

ifeq ($(shell uname), Linux)
	LFLAGS=-lcheck -lm -lsubunit
endif

all: quadratic_equation.a

quadratic_equation.a:
	gcc -c $(FLAGS) quadratic_equation.c
	ar rc quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a

check: quadratic_equation.a
	gcc $(FLAGS) -c test_quadratic_equation.c 
	gcc $(FLAGS) test_quadratic_equation.o -L. quadratic_equation.a $(LFLAGS) -o test
	./test

rebuild: clean all

clean:
	rm -rf quadratic_equation.a test *.o 
