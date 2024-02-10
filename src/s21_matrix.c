#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = OK;

  if ((result->matrix = (double **)malloc(rows * sizeof(double *)))) {
    for (int i = 0; i < rows && result_code == OK; i++) {
      if (!(result->matrix[i] = (double *)malloc(columns * sizeof(double)))) {
        result_code = INCORRECT;
      }
    }
    if (result_code == INCORRECT) {
      s21_remove_matrix(result);
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0.0;
      }
    }
  } else {
    result_code = INCORRECT;
  }

  return result_code;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A);
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

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (!(A->matrix[i][j] == B->matrix[i][j])) {
          result = FAILURE;
        }
      }
    }
  } else {
    result = FAILURE;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (s21_eq_matrix(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    result_code = ERRCALCUL;
  }
  return result_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (s21_eq_matrix(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    result_code = ERRCALCUL;
  }
  return result_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
}