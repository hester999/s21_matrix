//#include <check.h>
//
//#include "s21_matrix.h"
//#include "stdio.h"
//#define SUCCESS 1
//#define FAILURE 0
//#define OK 0
//#define ERROR 2
//
//START_TEST(test_s21_create_matrix) {
//  matrix_t my_matrix;
//  int ret = s21_create_matrix(4, 4, &my_matrix);
//  ck_assert_int_eq(ret, 0);
//  s21_remove_matrix(&my_matrix);
//
//  ret = s21_create_matrix(-4, 4, &my_matrix);
//  ck_assert_int_eq(ret, 1);
//
//  ret = s21_create_matrix(-4, 0, &my_matrix);
//  ck_assert_int_eq(ret, 1);
//}
//END_TEST
//
//START_TEST(test_s21_remove_matrix) {
//  matrix_t m;
//  s21_create_matrix(
//      3, 3,
//      &m);  // Предполагается, что функция вернёт 0 при успешной инициализации
//  s21_remove_matrix(&m);
//  ck_assert_ptr_null(m.matrix);
//  ck_assert_int_eq(m.rows, 0);
//  ck_assert_int_eq(m.columns, 0);
//}
//END_TEST
//
//START_TEST(test_s21_eq_matrix) {
//  matrix_t matrix_1, matrix_2;
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  int ret = s21_eq_matrix(&matrix_1, &matrix_2);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  ret = s21_eq_matrix(&matrix_1, &matrix_2);
//  ck_assert_int_eq(ret, 0);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(10, 10, &matrix_2);
//  ret = s21_eq_matrix(&matrix_1, &matrix_2);
//  ck_assert_int_eq(ret, 0);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  matrix_1.matrix[2][3] = -7;
//  ret = s21_eq_matrix(&matrix_1, &matrix_2);
//  ck_assert_int_eq(ret, 0);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  matrix_1.matrix[2][3] = -7;
//  matrix_2.matrix[2][3] = -7;
//  ret = s21_eq_matrix(&matrix_1, &matrix_2);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//}
//END_TEST
//
//START_TEST(test_s21_sum_matrix) {
//  matrix_t matrix_1, matrix_2, res_my, res_org;
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  int ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 5, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 2);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 5, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 2);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//      res_org.matrix[i][j] = i + j;
//    }
//  }
//  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//      matrix_2.matrix[i][j] = i + j;
//      res_org.matrix[i][j] = (i + j) * 2;
//    }
//  }
//  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//}
//END_TEST
//
//START_TEST(test_s21_sub_matrix) {
//  matrix_t matrix_1, matrix_2, res_my, res_org;
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  int ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 5, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 2);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 4, &matrix_2);
//  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//      res_org.matrix[i][j] = i + j;
//    }
//  }
//  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &matrix_2);
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//      matrix_2.matrix[i][j] = i + j;
//    }
//  }
//  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&matrix_2);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//}
//END_TEST
//
//START_TEST(test_s21_mult_number) {
//  matrix_t matrix_1, res_my, res_org;
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &res_org);
//  int ret = s21_mult_number(&matrix_1, 5, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 4, &matrix_1);
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//      res_org.matrix[i][j] = (i + j) * (-3);
//    }
//  }
//  ret = s21_mult_number(&matrix_1, -3, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(4, 4, &res_org);
//  for (int i = 0; i < 4; i++) {
//    for (int j = 0; j < 4; j++) {
//      matrix_1.matrix[i][j] = i + j;
//    }
//  }
//  ret = s21_mult_number(&matrix_1, 0, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_my, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix_1);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//}
//END_TEST
//
//START_TEST(test_s21_mult_matrix) {
//  matrix_t mat_1, mat_2, res_mat, orig;
//
//  s21_create_matrix(3, 3, &mat_1);
//  s21_create_matrix(3, 3, &mat_2);
//  mat_1.matrix[0][0] = 1;
//  mat_1.matrix[0][1] = 2;
//  mat_1.matrix[0][2] = 3;
//  mat_1.matrix[1][0] = 3;
//  mat_1.matrix[1][1] = 2;
//  mat_1.matrix[1][2] = 1;
//  mat_1.matrix[2][0] = 2;
//  mat_1.matrix[2][1] = 5;
//  mat_1.matrix[2][2] = 6;
//
//  mat_2.matrix[0][0] = 1;
//  mat_2.matrix[0][1] = 1;
//  mat_2.matrix[0][2] = 1;
//  mat_2.matrix[1][0] = 2;
//  mat_2.matrix[1][1] = 2;
//  mat_2.matrix[1][2] = 2;
//  mat_2.matrix[2][0] = 3;
//  mat_2.matrix[2][1] = 3;
//  mat_2.matrix[2][2] = 3;
//
//  int res = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
//  s21_create_matrix(3, 3, &orig);
//  orig.matrix[0][0] = 14;
//  orig.matrix[0][1] = 14;
//  orig.matrix[0][2] = 14;
//  orig.matrix[1][0] = 10;
//  orig.matrix[1][1] = 10;
//  orig.matrix[1][2] = 10;
//  orig.matrix[2][0] = 30;
//  orig.matrix[2][1] = 30;
//  orig.matrix[2][2] = 30;
//
//  int eq = s21_eq_matrix(&orig, &res_mat);
//  ck_assert_int_eq(eq, 1);
//
//  s21_remove_matrix(&mat_1);
//  s21_remove_matrix(&mat_2);
//  s21_remove_matrix(&res_mat);
//  s21_remove_matrix(&orig);
//
//  s21_create_matrix(4, 3, &mat_1);
//  s21_create_matrix(3, 3, &mat_2);
//
//  mat_1.matrix[0][0] = 1;
//  mat_1.matrix[0][1] = 2;
//  mat_1.matrix[0][2] = 3;
//  mat_1.matrix[1][0] = 3;
//  mat_1.matrix[1][1] = 2;
//  mat_1.matrix[1][2] = 1;
//  mat_1.matrix[2][0] = 2;
//  mat_1.matrix[2][1] = 5;
//  mat_1.matrix[2][2] = 6;
//
//  mat_2.matrix[0][0] = 1;
//  mat_2.matrix[0][1] = 1;
//  mat_2.matrix[0][2] = 1;
//  mat_2.matrix[1][0] = 2;
//  mat_2.matrix[1][1] = 2;
//  mat_2.matrix[1][2] = 2;
//  mat_2.matrix[2][0] = 3;
//  mat_2.matrix[2][1] = 3;
//  mat_2.matrix[2][2] = 3;
//
//  res = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
//  ck_assert_int_eq(res, 0);
//  s21_remove_matrix(&mat_1);
//  s21_remove_matrix(&mat_2);
//  s21_remove_matrix(&res_mat);
//}
//END_TEST
//
//START_TEST(test_s21_transpose) {
//  matrix_t mat_1, res_mat, res_org;
//
//  s21_create_matrix(2, 2, &mat_1);
//  s21_create_matrix(2, 2, &res_org);
//  mat_1.matrix[0][0] = 1;
//  mat_1.matrix[0][1] = 2;
//  mat_1.matrix[1][0] = 3;
//  mat_1.matrix[1][1] = 4;
//  res_org.matrix[0][0] = 1;
//  res_org.matrix[0][1] = 3;
//  res_org.matrix[1][0] = 2;
//  res_org.matrix[1][1] = 4;
//  int ret = s21_transpose(&mat_1, &res_mat);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_mat, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&mat_1);
//  s21_remove_matrix(&res_mat);
//  s21_remove_matrix(&res_org);
//
//  double matrix[2][2] = {
//      {1, 2},
//      {3, 4},
//  };
//  double res[2][2] = {{1, 3}, {2, 4}};
//  s21_create_matrix(2, 2, &mat_1);
//  s21_create_matrix(2, 2, &res_org);
//  for (int i = 0; i < 2; i++) {
//    for (int j = 0; j < 2; j++) {
//      mat_1.matrix[i][j] = matrix[i][j];
//    }
//  }
//  for (int i = 0; i < 2; i++) {
//    for (int j = 0; j < 2; j++) {
//      res_org.matrix[i][j] = res[i][j];
//    }
//  }
//  ret = s21_transpose(&mat_1, &res_mat);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_mat, &res_org);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&mat_1);
//  s21_remove_matrix(&res_mat);
//  s21_remove_matrix(&res_org);
//}
//END_TEST
//
//START_TEST(test_s21_determinant) {
//  matrix_t matrix;
//  s21_create_matrix(3, 3, &matrix);
//  int count = 1;
//  for (int i = 0; i < matrix.rows; i++) {
//    for (int j = 0; j < matrix.columns; j++) {
//      matrix.matrix[i][j] = count++;
//    }
//  }
//  matrix.matrix[2][2] = 10;
//  double res;
//  int ret = s21_determinant(&matrix, &res);
//  ck_assert_int_eq(res, -3);
//  ck_assert_int_eq(ret, 0);
//  s21_remove_matrix(&matrix);
//
//  s21_create_matrix(2, 3, &matrix);
//  ret = s21_determinant(&matrix, &res);
//  ck_assert_int_eq(ret, 2);
//  s21_remove_matrix(&matrix);
//
//  s21_create_matrix(1, 1, &matrix);
//  matrix.matrix[0][0] = 2;
//  s21_determinant(&matrix, &res);
//  ck_assert_int_eq(res, 2);
//  s21_remove_matrix(&matrix);
//}
//END_TEST
//
//START_TEST(test_s21_calc_complements) {
//  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
//  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
//  matrix_t matrix, res_org, res_my;
//  s21_create_matrix(3, 3, &matrix);
//  s21_create_matrix(3, 3, &res_org);
//  for (int i = 0; i < matrix.rows; i++) {
//    for (int j = 0; j < matrix.columns; j++) {
//      matrix.matrix[i][j] = m[i][j];
//    }
//  }
//  for (int i = 0; i < matrix.rows; i++) {
//    for (int j = 0; j < matrix.columns; j++) {
//      res_org.matrix[i][j] = r[i][j];
//    }
//  }
//  int ret = s21_calc_complements(&matrix, &res_my);
//  ck_assert_int_eq(ret, 0);
//  ret = s21_eq_matrix(&res_org, &res_my);
//  ck_assert_int_eq(ret, 1);
//  s21_remove_matrix(&matrix);
//  s21_remove_matrix(&res_my);
//  s21_remove_matrix(&res_org);
//
//  s21_create_matrix(2, 3, &matrix);
//  s21_create_matrix(3, 3, &res_org);
//  ret = s21_calc_complements(&matrix, &res_org);
//  ck_assert_int_eq(ret, 2);
//
//  s21_remove_matrix(&matrix);
//  s21_remove_matrix(&res_org);
//}
//END_TEST
//
//START_TEST(test_s21_inverse_matrix) {
//  matrix_t my_matrix, res_matrix, orig;
//
//  s21_create_matrix(3, 3, &orig);
//  orig.matrix[0][0] = -1;
//  orig.matrix[0][1] = 1;
//  orig.matrix[0][2] = -1;
//  orig.matrix[1][0] = 38;
//  orig.matrix[1][1] = -41;
//  orig.matrix[1][2] = 34;
//  orig.matrix[2][0] = -27;
//  orig.matrix[2][1] = 29;
//  orig.matrix[2][2] = -24;
//
//  s21_create_matrix(3, 3, &my_matrix);
//  my_matrix.matrix[0][0] = 2;
//  my_matrix.matrix[0][1] = 5;
//  my_matrix.matrix[0][2] = 7;
//  my_matrix.matrix[1][0] = 6;
//  my_matrix.matrix[1][1] = 3;
//  my_matrix.matrix[1][2] = 4;
//  my_matrix.matrix[2][0] = 5;
//  my_matrix.matrix[2][1] = -2;
//  my_matrix.matrix[2][2] = -3;
//
//  s21_inverse_matrix(&my_matrix, &res_matrix);
//
//  int ret = s21_eq_matrix(&res_matrix, &orig);
//
//  ck_assert_int_eq(ret, 0);
//  s21_remove_matrix(&my_matrix);
//  s21_remove_matrix(&res_matrix);
//  s21_remove_matrix(&orig);
//}
//END_TEST
//
//START_TEST(test_s21_inverse_matrix_2) {
//  matrix_t my_matrix, res_matrix, orig;
//
//  s21_create_matrix(1, 1, &orig);
//  s21_create_matrix(1, 1, &my_matrix);
//  s21_create_matrix(1, 1, &res_matrix);
//
//  orig.matrix[0][0] = 0.5;
//
//  my_matrix.matrix[0][0] = 2;
//  s21_inverse_matrix(&my_matrix, &res_matrix);
//  int ret = s21_eq_matrix(&res_matrix, &orig);
//  ck_assert_int_eq(ret, 1);
//
//  s21_create_matrix(3, 3, &my_matrix);
//
//  my_matrix.matrix[0][0] = 1;
//  my_matrix.matrix[0][1] = 2;
//  my_matrix.matrix[0][2] = 3;
//  my_matrix.matrix[1][0] = 4;
//  my_matrix.matrix[1][1] = 5;
//  my_matrix.matrix[1][2] = 6;
//  my_matrix.matrix[2][0] = 7;
//  my_matrix.matrix[2][1] = 8;
//  my_matrix.matrix[2][2] = 9;
//
//  ret = s21_inverse_matrix(&my_matrix, &orig);
//
//  ck_assert_int_eq(ret, 2);
//
//  s21_remove_matrix(&my_matrix);
//  s21_remove_matrix(&orig);
//}
//END_TEST
//
//Suite *s21_matrix_suite() {
//  Suite *s = suite_create("s21_matrix_test");
//
//  TCase *tc_s21_create_matrix = tcase_create("test_s21_create_matrix");
//  suite_add_tcase(s, tc_s21_create_matrix);
//  tcase_add_test(tc_s21_create_matrix, test_s21_create_matrix);
//
//  TCase *tc_s21_remove_matrix = tcase_create("s21_remove_matrix");
//  tcase_add_test(tc_s21_remove_matrix,
//                 test_s21_remove_matrix);  // Assuming your test function is
//                                           // named test_s21_remove_matrix
//  suite_add_tcase(s, tc_s21_remove_matrix);
//
//  TCase *tc_s21_eq_matrix = tcase_create("test_s21_eq_matrix");
//  suite_add_tcase(s, tc_s21_eq_matrix);
//  tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix);
//
//  TCase *tc_s21_sum_matrix = tcase_create("test_s21_sum_matrix");
//  suite_add_tcase(s, tc_s21_sum_matrix);
//  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix);
//
//  TCase *tc_s21_sub_matrix = tcase_create("test_s21_sub_matrix");
//  suite_add_tcase(s, tc_s21_sub_matrix);
//  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix);
//
//  TCase *tc_s21_mult_number = tcase_create("test_s21_mult_number");
//  suite_add_tcase(s, tc_s21_mult_number);
//  tcase_add_test(tc_s21_mult_number, test_s21_mult_number);
//
//  TCase *tc_s21_mult_matrix = tcase_create("test_s21_mult_matrix");
//  suite_add_tcase(s, tc_s21_mult_matrix);
//  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix);
//
//  TCase *tc_s21_transpose = tcase_create("test_s21_transpose");
//  suite_add_tcase(s, tc_s21_transpose);
//  tcase_add_test(tc_s21_transpose, test_s21_transpose);
//
//  TCase *tc_s21_determinant = tcase_create("test_s21_determinant");
//  suite_add_tcase(s, tc_s21_determinant);
//  tcase_add_test(tc_s21_determinant, test_s21_determinant);
//
//  TCase *tc_s21_calc_complements = tcase_create("test_s21_calc_complements");
//  suite_add_tcase(s, tc_s21_calc_complements);
//  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements);
//
//  TCase *tc_s21_inverse_matrix = tcase_create("test_s21_inverse_matrix");
//  suite_add_tcase(s, tc_s21_inverse_matrix);
//  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix);
//
//  TCase *tc_s21_inverse_matrix_2 = tcase_create("test_s21_inverse_matrix_2");
//  suite_add_tcase(s, tc_s21_inverse_matrix_2);
//  tcase_add_test(tc_s21_inverse_matrix_2, test_s21_inverse_matrix_2);
//
//  return s;
//}
//
//int main() {
//  int no_failed = 0;
//
//  Suite *s = s21_matrix_suite();
//
//  SRunner *runner = srunner_create(s);
//
//  srunner_run_all(runner, CK_NORMAL);
//  no_failed = srunner_ntests_failed(runner);
//  srunner_free(runner);
//
//  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
//}