#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 0;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = 1;
  } else if (A->columns > 0 && A->rows > 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  } else {
    flag = 2;
  }
  return flag;
}