#include "s21_matrix.h"

int matrix_valid(matrix_t *A) {
  int result_code = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    result_code = INCORRECT;
  }
  return result_code;
}

int s21_matrix_filling(matrix_t *result) {
  int result_code = OK;
  for (int i = 0; i < result->rows && result_code == OK; i++) {
    for (int j = 0; j < result->columns && result_code == OK; j++) {
      if (scanf("%lf", &result->matrix[i][j]) != 1) {
        result_code = INCORRECT;
      }
    }
  }
  return result_code;
}

double s21_mult_res(int i, int j, matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL) return 0;

  double res = 0;

  for (int k = 0; k < B->rows; k++) {
    res += A->matrix[i][k] * B->matrix[k][j];
  }

  return res;
}