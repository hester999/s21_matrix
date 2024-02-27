#include "s21_test.h"

START_TEST(test_create_matrix_sum_OK_1) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  matrix_t result;
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

  int res_eq = s21_sum_matrix(&matrix_A, &matrix_B, &result);

  ck_assert_double_eq(result.matrix[0][0], 2);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[1][0], 6);
  ck_assert_double_eq(result.matrix[1][1], 8);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
  if (res_eq == 0) s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_create_matrix_sum_OK_2) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  matrix_t result;
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

  int res_eq = s21_sum_matrix(&matrix_A, &matrix_B, &result);

  ck_assert_double_eq(result.matrix[0][0], 2.00000000234);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[1][0], 6);
  ck_assert_double_eq(result.matrix[1][1], 8);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
  if (res_eq == 0) s21_remove_matrix(&result);
}
END_TEST



START_TEST(sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, (void *)0), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  int answer = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//  проверка рандомными числами в матрицах 5 на 5
START_TEST(sum_matrix_3) {
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_test_empty) {
  matrix_t A = {0}, B = {0}, result = {0};
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
}

START_TEST(s21_sum_test_empty2) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
}

START_TEST(s21_sum_test_columns) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(CALCULATION_ERR0R, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_sum_test_rows) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(CALCULATION_ERR0R, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_sum_test_nulls) {
  matrix_t A = {0}, B = {0}, result = {0};
  A.rows = A.columns = B.rows = B.columns = 8;
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
}

START_TEST(s21_sum_test_Anull) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&B);
}

START_TEST(s21_sum_test_Bnull) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
}

START_TEST(s21_sum_test1) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 9668.9786796878867;
  B.matrix[0][0] = 97.689698767;
  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &result));
  ck_assert_int_eq(A.matrix[0][0] + B.matrix[0][0], result.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_test2) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &result);

  result.matrix[0][0] = A.matrix[0][0] = B.matrix[0][0] = 0.1;
  result.matrix[0][0] += result.matrix[0][0];
  result.matrix[0][1] = A.matrix[0][1] = B.matrix[0][1] = 8.8;
  result.matrix[0][1] += result.matrix[0][1];
  result.matrix[1][0] = A.matrix[1][0] = B.matrix[1][0] = 534.454356;
  result.matrix[1][0] += result.matrix[1][0];
  result.matrix[1][1] = A.matrix[1][1] = B.matrix[1][1] = 5.3;
  result.matrix[1][1] += result.matrix[1][1];
  result.matrix[2][0] = A.matrix[2][0] = B.matrix[2][0] = 87677.956785644;
  result.matrix[2][0] += result.matrix[2][0];
  result.matrix[2][1] = A.matrix[2][1] = B.matrix[2][1] = 567347.345774555;
  result.matrix[2][1] += result.matrix[2][1];

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &test_result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &test_result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_sum_test3) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &result);

  result.matrix[0][0] = A.matrix[0][0] = B.matrix[0][0] = 0.1;
  result.matrix[0][0] += result.matrix[0][0];
  result.matrix[0][1] = A.matrix[0][1] = B.matrix[0][1] = -8.8;
  result.matrix[0][1] += result.matrix[0][1];
  result.matrix[1][0] = A.matrix[1][0] = B.matrix[1][0] = 534.454356;
  result.matrix[1][0] += result.matrix[1][0];
  result.matrix[1][1] = A.matrix[1][1] = B.matrix[1][1] = 5.3;
  result.matrix[1][1] += result.matrix[1][1];
  result.matrix[2][0] = A.matrix[2][0] = B.matrix[2][0] = 87677.956785644;
  result.matrix[2][0] += result.matrix[2][0];
  A.matrix[2][1] = 4355353.434534545;
  B.matrix[2][1] = 567347.345774555;
  result.matrix[2][1] = A.matrix[2][1] + B.matrix[2][1];

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &test_result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &test_result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

Suite *test_matrix_sum(void) {
  Suite *s = suite_create("\033[45m-=S21_MATRIX_SUM=-\033[0m");
  TCase *tc = tcase_create("matrix_create_tc");

  tcase_add_test(tc, test_create_matrix_sum_OK_1);
  tcase_add_test(tc, test_create_matrix_sum_OK_2);


  tcase_add_test(tc, sum_matrix);
  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, s21_sum_test_empty);
  tcase_add_test(tc, s21_sum_test_empty2);
  tcase_add_test(tc, s21_sum_test_columns);
  tcase_add_test(tc, s21_sum_test_rows);
  tcase_add_test(tc, s21_sum_test_nulls);
  tcase_add_test(tc, s21_sum_test_Anull);
  tcase_add_test(tc, s21_sum_test_Bnull);
  tcase_add_test(tc, s21_sum_test1);
  tcase_add_test(tc, s21_sum_test2);
  tcase_add_test(tc, s21_sum_test3);

  suite_add_tcase(s, tc);
  return s;
}
