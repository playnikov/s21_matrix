#include "s21_matrix.h"

int main() {
  int result_code = OK;
  matrix_t matrixA;
  matrixA.rows = 3;
  matrixA.columns = 4;
  matrix_t matrixB;
  matrixB.rows = 5;
  matrixB.columns = 4;
  s21_create_matrix(matrixA.rows, matrixA.columns, &matrixA);
  result_code = s21_matrix_filling(&matrixA);
  printf("\n");
  s21_create_matrix(matrixB.rows, matrixB.columns, &matrixB);
  s21_matrix_filling(&matrixB);
  printf("%d\n", s21_eq_matrix(&matrixA, &matrixB));
  result_code = OK;
  return result_code;
}