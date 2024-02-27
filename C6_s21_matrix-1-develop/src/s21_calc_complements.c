#include "s21_matrix.h"

void getMinorMatrix(int row, int column, matrix_t *A, matrix_t *result) {
  int minorRow = 0, minorCol = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      result->matrix[minorRow][minorCol] = A->matrix[i][j];
      minorCol++;
    }
    minorRow++;
    minorCol = 0;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = 1;
  } else if (A->columns > 0 && A->rows > 0 && A->columns == A->rows) {
    matrix_t matrixForMinor;
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &matrixForMinor);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor = 0;
        getMinorMatrix(i, j, A, &matrixForMinor);
        s21_determinant(&matrixForMinor, &minor);
        result->matrix[i][j] = pow((-1), (i + j)) * minor;
      }
    }
    s21_remove_matrix(&matrixForMinor);
  } else {
    flag = 2;
  }
  return flag;
}