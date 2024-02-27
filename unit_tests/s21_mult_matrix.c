#include "s21_test.h"
#include "stdio.h"
START_TEST(s21_mult_test_empty) {
  matrix_t A = {0}, B = {0}, result = {0};
  int ret =s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX,ret );
}

START_TEST(s21_mult_test_empty2) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int ret = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, ret);
}

START_TEST(s21_mult_test_columns) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_test_zeroes) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  int ret =s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, ret);
  ck_assert_ldouble_eq_tol(0, result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_test_nulls) {
  matrix_t A = {0}, B = {0}, result = {0};
  A.rows = A.columns = B.rows = B.columns = 8;
  int ret =s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, ret);
}

START_TEST(s21_mult_test_Anull) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&B);
}

START_TEST(s21_mult_test_Bnull) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(FAIL_INCORRECT_MATRIX, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
}

START_TEST(s21_mult_test_rows) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(CALCULATION_ERR0R, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_test1) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 9668.9786796878867;
  B.matrix[0][0] = 97.689698767;
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_ldouble_eq_tol(A.matrix[0][0] * B.matrix[0][0], result.matrix[0][0],
                           1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_test2) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &result);

  A.matrix[0][0] = B.matrix[0][0] = 0.1;
  A.matrix[0][1] = B.matrix[0][1] = 8.8;
  A.matrix[1][0] = B.matrix[0][2] = 534.454356;
  A.matrix[1][1] = B.matrix[1][0] = 5.3;
  A.matrix[2][0] = B.matrix[1][1] = -87677.956785644;
  A.matrix[2][1] = B.matrix[1][2] = 567347.345774554;

  result.matrix[0][0] =
      A.matrix[0][0] * B.matrix[0][0] + A.matrix[0][1] * B.matrix[1][0];
  result.matrix[0][1] =
      A.matrix[0][0] * B.matrix[0][1] + A.matrix[0][1] * B.matrix[1][1];
  result.matrix[0][2] =
      A.matrix[0][0] * B.matrix[0][2] + A.matrix[0][1] * B.matrix[1][2];

  result.matrix[1][0] =
      A.matrix[1][0] * B.matrix[0][0] + A.matrix[1][1] * B.matrix[1][0];
  result.matrix[1][1] =
      A.matrix[1][0] * B.matrix[0][1] + A.matrix[1][1] * B.matrix[1][1];
  result.matrix[1][2] =
      A.matrix[1][0] * B.matrix[0][2] + A.matrix[1][1] * B.matrix[1][2];

  result.matrix[2][0] =
      A.matrix[2][0] * B.matrix[0][0] + A.matrix[2][1] * B.matrix[1][0];
  result.matrix[2][1] =
      A.matrix[2][0] * B.matrix[0][1] + A.matrix[2][1] * B.matrix[1][1];
  result.matrix[2][2] =
      A.matrix[2][0] * B.matrix[0][2] + A.matrix[2][1] * B.matrix[1][2];

  int ret1 =s21_mult_matrix(&A, &B, &test_result);
  ck_assert_int_eq(OK, ret1);

  int ret2 = s21_eq_matrix(&result, &test_result);
  ck_assert_int_eq(SUCCESS, ret2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_mult_test3) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(2, 2, &result);

  // A = m × k на матрицу B = k × n
  //  C = m × n =  C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) ×
  //  B(k,j)

  A.matrix[0][0] = 0;
  A.matrix[1][0] = 0.00000000032324;
  B.matrix[0][0] = 0.1;
  B.matrix[0][1] = -98087.987987098798;

  result.matrix[0][0] = A.matrix[0][0] * B.matrix[0][0];
  result.matrix[0][1] = A.matrix[0][0] * B.matrix[0][1];

  result.matrix[1][0] = A.matrix[1][0] * B.matrix[0][0];

  result.matrix[1][1] = A.matrix[1][0] * B.matrix[0][1];

  int ret =  s21_mult_matrix(&A, &B, &test_result);

  ck_assert_int_eq(OK, ret);

  int ret1 = s21_eq_matrix(&result, &test_result);

  ck_assert_int_eq(SUCCESS, ret1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(s21_mult_test4) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(1, 1, &result);

  // A = m × k на матрицу B = k × n
  //  C = m × n =  C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) ×
  //  B(k,j)

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0.00000000032324;
  B.matrix[0][0] = 0.1;
  B.matrix[1][0] = -98087.987987098798;

  result.matrix[0][0] =
      A.matrix[0][0] * B.matrix[0][0] + A.matrix[0][1] * B.matrix[1][0];

  printf("%f\n",result.matrix[0][0]);
  int a = s21_mult_matrix(&A, &B, &test_result);
  ck_assert_int_eq(OK, a);
  int ret = s21_eq_matrix(&result, &test_result);
  ck_assert_int_eq(SUCCESS, ret);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_matrix((void *)0, NULL, &result),
                   FAIL_INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), FAIL_INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A = {0}, B = {0}, result = {0};
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 1, &B);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  B.matrix[0][0] = 2.;
  B.matrix[1][0] = 1.;
  B.matrix[2][0] = 2.;
  int answer = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_test(void) {
  Suite *s = suite_create("\033[45m-=S21_MATRIX_MUL=-\033[0m");
  TCase *tc = tcase_create("case_s21_mult_matrix");

  tcase_add_test(tc, s21_mult_test_empty);
  tcase_add_test(tc, s21_mult_test_empty2);
  tcase_add_test(tc, s21_mult_test_columns);
  tcase_add_test(tc, s21_mult_test_zeroes);
  tcase_add_test(tc, s21_mult_test_nulls);
  tcase_add_test(tc, s21_mult_test_rows);
  tcase_add_test(tc, s21_mult_test_Anull);
  tcase_add_test(tc, s21_mult_test_Bnull);
  tcase_add_test(tc, s21_mult_test1);
  tcase_add_test(tc, s21_mult_test2);
  tcase_add_test(tc, s21_mult_test3);
  tcase_add_test(tc, s21_mult_test4);
  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}