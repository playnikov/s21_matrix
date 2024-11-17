#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!s21_matrix_empty(A) && !s21_matrix_empty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      result_code = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && result_code == OK; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      result_code = CALCULATION_ERROR;
    }
  } else {
    result_code = UNCORRECTED;
  }
  return result_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!s21_matrix_empty(A) && !s21_matrix_empty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      result_code = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && result_code == OK; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      result_code = CALCULATION_ERROR;
    }
  } else {
    result_code = UNCORRECTED;
  }
  return result_code;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = OK;
  if (!s21_matrix_empty(A)) {
    result_code = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && result_code == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    result_code = UNCORRECTED;
  }
  return result_code;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!s21_matrix_empty(A) && !s21_matrix_empty(B)) {
    if (A->columns == B->rows) {
      result_code = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows && result_code == OK; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      result_code = CALCULATION_ERROR;
    }
  } else {
    result_code = UNCORRECTED;
  }
  return result_code;
}
