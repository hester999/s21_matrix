#include "s21_matrix.h"

#include "stdio.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = 0;

  if (rows < 1 || columns < 1 || result == NULL) {
    err = 1;
    result->matrix = NULL;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    } else {
      err = 1;
    }
  }

  return err;
}

void s21_remove_matrix(matrix_t *A) {

  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }

  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;

  if (s21_valid_matrix(A) && s21_valid_matrix(B) && A->matrix != NULL &&
      B->matrix != NULL && A->rows == B->rows && A->columns == B->columns) {
    result = SUCCESS;
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
          result = FAILURE;
          break;
        }
      }
      if (result == FAILURE) {
        break;
      }
    }
  }

  return result;
}

int s21_valid_matrix(matrix_t *matrix) {
  int res = 0;
  if (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
      matrix->columns >= 1) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = 0;

  if (s21_valid_matrix(A) && s21_valid_matrix(B)) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      err = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }

    } else {
      err = 2;
    }
  } else {
    err = 1;
  }
  return err;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = 0;

  if (s21_valid_matrix(A) && s21_valid_matrix(B)) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      err = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }

    } else {
      err = 2;
    }
  } else {
    err = 1;
  }
  return err;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = 0;
  if (isnan(number) || isinf(number) || result == NULL) {
    return 1;
  }

  if (s21_valid_matrix(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    err = 1;
  }

  return err;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = 0;
  if (s21_valid_matrix(A) && s21_valid_matrix(B)) {
    if (A->columns == B->rows) {
      err = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
              double sum = 0;
              for (int k = 0; k < B->rows; k++) {
                sum  = sum +A->matrix[i][k] * B->matrix[k][j];
              }
          result->matrix[i][j] = sum;
        }
      }
    } else {
      err = 2;
    }
  } else {
    err = 1;
  }
  return err;
}






int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = 0;
  if (s21_valid_matrix(A)) {
    err = s21_create_matrix(A->columns, A->rows, result);
    if(s21_valid_matrix(result)){
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[j][i] = A->matrix[i][j];
            }
        }
    }else{
        err =1 ;
    }

  } else {
    err = 1;
  }
  return err;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = 0;

  if (s21_valid_matrix(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor_matrix = {0};
          if(A->rows ==1){
              err = s21_create_matrix(1,1,result);
              result->matrix[0][0] = 1;
          }else{
              err = s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);

              if (!err) {
                err = s21_get_minor(A, &minor_matrix, i, j);
              }
              double temp = 0;
              s21_determinant(&minor_matrix, &temp);
              result->matrix[i][j] = pow(-1, i + j) * temp;

              s21_remove_matrix(&minor_matrix);
          }
        }
      }
    } else {
      err = 2;
    }
  } else {
    err = 1;
  }

  return err;
}

int s21_get_minor(matrix_t *A, matrix_t *minor_matrix, int remove_row,
                  int remove_colum) {
  int err = 0;
  int r = 0;
  int c = 0;

  if (s21_valid_matrix(minor_matrix)) {
    for (int i = 0; i < A->rows; i++) {
      if (i == remove_row) {
        continue;
      }
      c = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j == remove_colum) {
          continue;
        }
        minor_matrix->matrix[r][c] = A->matrix[i][j];
        c++;
      }
      r++;
    }
  } else {
    err = 1;
  }

  return err;
}

int s21_determinant(matrix_t *A, double *result) {
  int err = 0;

  *result = 0;
  if (s21_valid_matrix(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1 && A->columns == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2 && A->columns == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1]) -
                  (A->matrix[0][1] * A->matrix[1][0]);
      } else {
        double res = 0;
        for (int k = 0; k < A->rows; k++) {
          matrix_t minor = {0};
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          for (int i = 1; i < A->rows; i++) {
            for (int j = 0, col = 0; j < A->rows; j++) {
              if (k == j) continue;
              minor.matrix[i - 1][col] = A->matrix[i][j];
              col++;
            }
          }
          double minor_result = 0.0;
          s21_determinant(&minor, &minor_result);
          res += pow(-1, k) * A->matrix[0][k] * minor_result;
          s21_remove_matrix(&minor);
        }
        *result = res;
      }
    } else {
      err = 2;
    }

  } else {
    err = 1;
  }

  return err;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = 0;

  if (s21_valid_matrix(A)) {
    err = s21_create_matrix(A->rows, A->columns, result);

    if (A->rows == 1 && s21_valid_matrix(result) && (A->matrix[0][0]!= 0)) {
      result->matrix[0][0] = (1 / A->matrix[0][0]);
    } else {
      double det = 0;
      err = s21_determinant(A, &det);
      if (det == 0 && !err) {
        err = 2;
      } else if (det != 0 && !err) {
        matrix_t temp_matrix = {0};
        matrix_t temp_matrix_2 = {0};
        s21_calc_complements(A, &temp_matrix);
        s21_transpose(&temp_matrix, &temp_matrix_2);
        s21_mult_number(&temp_matrix_2,1.0/det,result);
          s21_remove_matrix(&temp_matrix);
          s21_remove_matrix(&temp_matrix_2);
      }
    }
  } else {
    err = 1;
  }

  return err;
}