#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;
  double determ;
  s21_determinant(A, &determ);
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = 1;
  } else if (determ == 0 || (A->columns != A->rows)) {
    flag = 2;
  } else {
    matrix_t calc = {0}, trans = {0};
    s21_calc_complements(A, &calc);
    s21_create_matrix(A->rows, A->columns, result);
    s21_transpose(&calc, &trans);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = 1.0 / determ * trans.matrix[i][j];
      }
    }
    s21_remove_matrix(&calc);
    s21_remove_matrix(&trans);
  }
  return flag;
}