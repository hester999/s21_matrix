#include "s21_matrix.h"
#include "stdio.h"
int main() {
  matrix_t A = {0}, result = {0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &result);
  A.matrix[0][0] = 2;

  s21_inverse_matrix(&A, &result);

  printf("%lf\n", result.matrix[0][0]);

  return 0;
}
