#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (A->rows <= 0 || A->columns <= 0) {
    flag = 1;
  } else if (A->columns > 0 && A->rows > 0) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    flag = 2;
  }
  return flag;
}