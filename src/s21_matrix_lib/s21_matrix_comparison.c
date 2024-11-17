#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (!s21_matrix_empty(A) && !s21_matrix_empty(B) &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          result_code = FAILURE;
        }
      }
    }
  } else {
    result_code = FAILURE;
  }

  return result_code;
}