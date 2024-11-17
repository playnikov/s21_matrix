#include "../s21_matrix.h"

int s21_matrix_empty(matrix_t *matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

void s21_get_matrix(matrix_t *A, matrix_t *result, int row, int column) {
  int m_row = 0, m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      m_col = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          result->matrix[m_row][m_col] = A->matrix[i][j];
          m_col++;
        }
      }
      m_row++;
    }
  }
}