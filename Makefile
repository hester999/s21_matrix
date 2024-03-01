FLAGS = -Wall -Wextra -Werror  -std=c11

all: s21_matrix.a test gcov_report



s21_matrix.a:
	gcc $(FLAGS) -c s21_matrix.c
	ar rc s21_matrix.a  s21_matrix.o
	rm s21_matrix.o
#
#test:
#		gcc $(FLAGS) -c  s21_test.c
#		gcc $(FLAGS) -c s21_matrix.c --coverage
#		gcc $(FLAGS) -o s21_test *.o -lcheck --coverage
#		./s21_test

test:
	 	gcc ./unit_tests/s21_*.c -c $(FLAGS) --coverage
	    gcc s21_*.o s21_matrix.a -o test -lcheck  $(FLAGS) --coverage
	 ./test

gcov_report: test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html


clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_matrix.a ./test