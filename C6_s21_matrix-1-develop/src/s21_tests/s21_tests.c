#include <check.h>

#include "../s21_matrix.h"

START_TEST(create_1) {
  matrix_t test = {0};
  int rows = 0;
  int columns = 3;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_2) {
  matrix_t test = {0};
  int rows = 3;
  int columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), 1);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_3) {
  matrix_t test = {0};
  int rows = 1;
  int columns = 3;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), 0);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(remove_1) {
  matrix_t test = {0};
  int rows = 1;
  int columns = 3;
  s21_create_matrix(rows, columns, &test);
  s21_remove_matrix(&test);
  ck_assert_int_eq(test.rows, 0);
  ck_assert_int_eq(test.columns, 0);
}
END_TEST

START_TEST(eq_1) {
  matrix_t test_1 = {0}, test_2 = {0};
  int rows_1 = 1, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  test_1.matrix[0][0] = 0;
  test_1.matrix[0][1] = 1;
  test_1.matrix[0][2] = 2;
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 1;
  test_2.matrix[0][2] = 2;
  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), SUCCESS);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(eq_2) {
  matrix_t test_1 = {0}, test_2 = {0};
  int rows_1 = 1, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), FAILURE);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(eq_3) {
  matrix_t test_1 = {0}, test_2 = {0};
  int rows_1 = 1, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  test_1.matrix[0][0] = 0;
  test_1.matrix[0][1] = 0;
  test_1.matrix[0][2] = 0;
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 1;
  test_2.matrix[0][2] = 2;
  ck_assert_int_eq(s21_eq_matrix(&test_1, &test_2), FAILURE);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
}
END_TEST

START_TEST(sum_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  test_1.matrix[0][0] = 0;
  test_1.matrix[0][1] = 1;
  test_1.matrix[0][2] = 2;
  s21_create_matrix(rows_2, columns_2, &test_2);
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 1;
  test_2.matrix[0][2] = 2;
  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result), 0);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      test_1.matrix[i][j] = rand() % 2;
    }
  }
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 2;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result), 2);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 0, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 2;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&test_1, &test_2, &result), 1);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  test_1.matrix[0][0] = 0;
  test_1.matrix[0][1] = 1;
  test_1.matrix[0][2] = 2;
  s21_create_matrix(rows_2, columns_2, &test_2);
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 1;
  test_2.matrix[0][2] = 2;
  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result), 0);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      test_1.matrix[i][j] = rand() % 2;
    }
  }
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 2;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result), 2);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 0, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 2;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&test_1, &test_2, &result), 1);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_1) {
  matrix_t test = {0}, result = {0};
  double number = rand() % 10;
  int rows = 1, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_mult_number(&test, number, &result), 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t test = {0}, result = {0};
  double number = rand() % 10;
  int rows = 0, columns = 3;
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_mult_number(&test, number, &result), 1);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 3;
  int columns_1 = 3, columns_2 = 1;
  s21_create_matrix(rows_1, columns_1, &test_1);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      test_1.matrix[i][j] = rand() % 10;
    }
  }
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result), 0);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 1, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      test_1.matrix[i][j] = rand() % 10;
    }
  }
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result), 2);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t test_1 = {0}, test_2 = {0}, result = {0};
  int rows_1 = 0, rows_2 = 1;
  int columns_1 = 3, columns_2 = 3;
  s21_create_matrix(rows_1, columns_1, &test_1);
  s21_create_matrix(rows_2, columns_2, &test_2);
  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      test_2.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test_1, &test_2, &result), 1);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t test = {0}, result = {0};
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_transpose(&test, &result), 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t test = {0}, result = {0};
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  s21_transpose(&test, &result);
  ck_assert_int_eq(test.rows, result.columns);
  ck_assert_int_eq(test.columns, result.rows);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t test = {0}, result = {0};
  int rows = 0, columns = 3;
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_transpose(&test, &result), 1);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_1) {
  matrix_t test = {0}, result = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&test, &result), 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_2) {
  matrix_t test = {0}, result = {0};
  int rows = 0, columns = 3;
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_calc_complements(&test, &result), 1);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_3) {
  matrix_t test = {0}, result = {0};
  int rows = 1, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&test, &result), 2);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_4) {
  matrix_t test_1 = {0};
  s21_create_matrix(3, 3, &test_1);
  matrix_t res = {0};
  s21_create_matrix(3, 3, &res);
  matrix_t test_2;
  test_1.matrix[0][0] = 1;
  test_1.matrix[0][1] = 2;
  test_1.matrix[0][2] = 3;
  test_1.matrix[1][0] = 0;
  test_1.matrix[1][1] = 4;
  test_1.matrix[1][2] = 2;
  test_1.matrix[2][0] = 5;
  test_1.matrix[2][1] = 2;
  test_1.matrix[2][2] = 1;
  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;
  s21_calc_complements(&test_1, &test_2);
  ck_assert_int_eq(s21_eq_matrix(&res, &test_2), SUCCESS);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&test_1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t test = {0};
  double result = 0;
  int rows = 1, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_determinant(&test, &result), 2);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_2) {
  const int size = 5;
  matrix_t test = {0};
  s21_create_matrix(size, size, &test);
  test.matrix[0][1] = 6;
  test.matrix[0][2] = -2;
  test.matrix[0][3] = -1;
  test.matrix[0][4] = 5;
  test.matrix[1][3] = -9;
  test.matrix[1][4] = -7;
  test.matrix[2][1] = 15;
  test.matrix[2][2] = 35;
  test.matrix[3][1] = -1;
  test.matrix[3][2] = -11;
  test.matrix[3][3] = -2;
  test.matrix[3][4] = 1;
  test.matrix[4][0] = -2;
  test.matrix[4][1] = -2;
  test.matrix[4][2] = 3;
  test.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&test, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_4) {
  const int size = 3;
  matrix_t test = {0};
  s21_create_matrix(size, size, &test);
  test.matrix[0][0] = 2;
  test.matrix[0][1] = 3;
  test.matrix[0][2] = 1;
  test.matrix[1][0] = 7;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 1;
  test.matrix[2][0] = 9;
  test.matrix[2][1] = -2;
  test.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&test, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_5) {
  const int size = 2;
  matrix_t test = {0};
  s21_create_matrix(size, size, &test);
  test.matrix[0][0] = -5;
  test.matrix[0][1] = -4;
  test.matrix[1][0] = -2;
  test.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&test, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&test);
}
END_TEST

START_TEST(inverse_1) {
  matrix_t test = {0}, result = {0};
  int rows = 1, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&test, &result), 2);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t test = {0}, result = {0};
  int rows = 0, columns = 3;
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_inverse_matrix(&test, &result), 1);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t test = {0}, result = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &test);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = rand() % 10;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&test, &result), 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

int main(void) {
  int flag = 0;
  Suite *s = suite_create("s21_matrix: ");
  SRunner *sr = srunner_create(s);
  TCase *tc = tcase_create("s21_matrix: ");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, remove_1);
  tcase_add_test(tc, eq_1);
  tcase_add_test(tc, eq_2);
  tcase_add_test(tc, eq_3);
  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, calc_1);
  tcase_add_test(tc, calc_2);
  tcase_add_test(tc, calc_3);
  tcase_add_test(tc, calc_4);
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);
  tcase_add_test(tc, inverse_3);
  tcase_add_test(tc, inverse_4);
  srunner_run_all(sr, CK_ENV);

  int fails = srunner_ntests_failed(sr);

  srunner_free(sr);
  if (fails != 0) flag = 1;
  return flag;
}