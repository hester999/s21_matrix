#include "s21_test.h"

START_TEST(test_create_matrix_ok_1) {
  matrix_t matrix;
  int rows = 2;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_ok_2) {
  matrix_t matrix;
  int rows = 10;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_ok_3) {
  matrix_t matrix;
  int rows = 2;
  int columns = 10;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_fail_1) {
  matrix_t matrix;

  int res = s21_create_matrix(0, 5, &matrix);
  ck_assert_int_eq(res, 1);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_fail_2) {
  matrix_t matrix;

  int res = s21_create_matrix(-4, 5, &matrix);
  ck_assert_int_eq(res, 1);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

Suite *test_matrix_create(void) {
  Suite *s = suite_create("\033[45m-=S21_MATRIX_CREATE=-\033[0m");
  TCase *tc = tcase_create("matrix_create_tc");

  tcase_add_test(tc, test_create_matrix_ok_1);
  tcase_add_test(tc, test_create_matrix_ok_2);
  tcase_add_test(tc, test_create_matrix_ok_3);
  tcase_add_test(tc, test_create_matrix_fail_1);
  tcase_add_test(tc, test_create_matrix_fail_2);

  suite_add_tcase(s, tc);
  return s;
}
