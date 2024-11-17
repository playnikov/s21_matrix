#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = OK;
  if (rows < 1 || columns < 1) {
    result_code = UNCORRECTED;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(result->rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(result->columns, sizeof(double));
    }

    for (int i = 0; i < columns; i++) {
      for (int j = 0; j < rows; j++) {
        result->matrix[j][i] = 0;
      }
    }
  }
  return result_code;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->rows = 0;
  A->columns = 0;
}