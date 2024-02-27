#include "s21_test.h"

START_TEST(test_create_matrix_eq_OK_1) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1, 2}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, SUCCESS);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_create_matrix_eq_OK_2) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1.00000000234, 2}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, SUCCESS);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_create_matrix_eq_FAIL_1) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1, 3}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_create_matrix_eq_FAIL_2) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1.001, 3}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_create_matrix_eq_FAIL_3) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{0, 0}, {0.000001, 0}};
  double matrix_B1[2][2] = {{0, 0}, {0, 0}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_create_matrix_eq_FAIL_4) {
  matrix_t matrix_A = {0, 4, 0};
  matrix_t matrix_B = {0, 4, 0};

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);
}
END_TEST

Suite *test_matrix_eq(void) {
  Suite *s = suite_create("\033[45m-=S21_MATRIX_EQ=-\033[0m");
  TCase *tc = tcase_create("matrix_create_tc");

  tcase_add_test(tc, test_create_matrix_eq_OK_1);
  tcase_add_test(tc, test_create_matrix_eq_OK_2);
  tcase_add_test(tc, test_create_matrix_eq_FAIL_1);
  tcase_add_test(tc, test_create_matrix_eq_FAIL_2);
  tcase_add_test(tc, test_create_matrix_eq_FAIL_3);
  tcase_add_test(tc, test_create_matrix_eq_FAIL_4);

  suite_add_tcase(s, tc);
  return s;
}
