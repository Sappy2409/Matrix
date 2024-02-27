#include "s21_matrix.h"

void swap(matrix_t *A, matrix_t *temp, int i, int k, int max) {
  for (k = 0; k < A->rows; k++) {
    temp->matrix[i][k] = A->matrix[i][k];
    A->matrix[i][k] = A->matrix[max][k];
    A->matrix[max][k] = temp->matrix[i][k];
  }
}

void get_det(matrix_t *A, double *result) {
  matrix_t temp = {0};
  int rows_temp = A->rows;
  int columns_temp = A->columns;
  double index;
  int k = 0, max = 0;
  *result = 1.0;
  s21_create_matrix(rows_temp, columns_temp, &temp);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      temp.matrix[i][j] = A->matrix[i][j];
    }
  }
  for (int i = 0; i < A->rows; i++) {
    max = i;
    for (int j = i + 1; j < A->columns; j++) {
      if (fabs(A->matrix[j][i]) > fabs(A->matrix[i][i])) max = j;
    }
    if (max != i) {
      *result *= -1;
      swap(A, &temp, i, k, max);
    }
    if (A->matrix[i][i] == 0) {
      *result = 0;
    } else {
      *result *= A->matrix[i][i];
      for (int j = i + 1; j < A->rows; j++) {
        index = A->matrix[j][i] / A->matrix[i][i];
        for (k = i; k < A->columns; k++) {
          A->matrix[j][k] -= A->matrix[i][k] * index;
        }
      }
    }
  }
  s21_remove_matrix(&temp);
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = 0;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    flag = 1;
  } else if (A->columns == A->rows) {
    matrix_t saveMatrix;
    s21_create_matrix(A->rows, A->columns, &saveMatrix);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        saveMatrix.matrix[i][j] = A->matrix[i][j];
      }
    }
    get_det(A, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = saveMatrix.matrix[i][j];
      }
    }
    s21_remove_matrix(&saveMatrix);
  } else {
    flag = 2;
  }
  return flag;
}