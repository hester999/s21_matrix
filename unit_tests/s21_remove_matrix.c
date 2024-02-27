#include "s21_test.h"
#include "stdio.h"

START_TEST(test_remove_matrix_1) {
  matrix_t matrix;
  int rows = 2;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_2) {
  matrix_t matrix;
  int rows = 10;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_3) {
  matrix_t matrix;
  int rows = 2;
  int columns = 10;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_4) {
  matrix_t matrix;

  s21_create_matrix(0, 5, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_5) {
  matrix_t matrix;

  s21_create_matrix(-4, 5, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

Suite *test_matrix_remove(void) {
  Suite *s = suite_create("\033[45m-=S21_MATRIX_REMOVE=-\033[0m");
  TCase *tc = tcase_create("matrix_remove_tc");

  tcase_add_test(tc, test_remove_matrix_1);
  tcase_add_test(tc, test_remove_matrix_2);
  tcase_add_test(tc, test_remove_matrix_3);
  tcase_add_test(tc, test_remove_matrix_4);
  tcase_add_test(tc, test_remove_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}