#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

#include "../s21_matrix.h"
#define OK 0
#define FAIL_INCORRECT_MATRIX 1
#define CALCULATION_ERR0R 2

Suite *test_matrix_create(void);
Suite *test_matrix_remove(void);
Suite *test_matrix_eq(void);
Suite *test_matrix_sum(void);
Suite *test_matrix_sub(void);
Suite *test_matrix_mul(void);
Suite *s21_mult_matrix_test(void);
Suite *test_matrix_transpose(void);
Suite *test_matrix_determinant(void);
Suite *s21_calc_complements_test(void);
Suite *suite_inverse_matrix(void);

typedef struct {
  int fails;
} fail;

void run_tests(fail *fails);
void run_testcase(Suite *testcase, fail *fails);

#endif