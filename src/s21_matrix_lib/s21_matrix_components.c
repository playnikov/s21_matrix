#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (!s21_matrix_empty(A)) {
    result_code = s21_create_matrix(A->columns, A->rows, result);
    if (result_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    result_code = UNCORRECTED;
  }
  return result_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = OK;

  if (s21_matrix_empty(A)) {
    result_code = UNCORRECTED;
  } else if (A->rows != A->columns) {
    result_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double detA;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_get_matrix(A, &minor, i, j);
        s21_determinant(&minor, &detA);
        result->matrix[i][j] = pow(-1, i + j) * detA;
        s21_remove_matrix(&minor);
      }
    }
  }

  return result_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int result_code = OK;
  if (s21_matrix_empty(A)) {
    result_code = UNCORRECTED;
  } else if (A->rows != A->columns) {
    result_code = CALCULATION_ERROR;
  } else {
    *result = s21_get_determinant(A);
  }

  return result_code;
}

double s21_get_determinant(matrix_t *A) {
  double result = 0.0;
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    int sign = 1;
    matrix_t temp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
    for (int i = 0; i < A->columns; i++) {
      s21_get_matrix(A, &temp, 0, i);
      result += (sign * A->matrix[0][i] * s21_get_determinant(&temp));
      sign = -sign;
    }
    s21_remove_matrix(&temp);
  }
  return result;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (s21_matrix_empty(A)) {
    result_code = UNCORRECTED;
  } else {
    double detA;
    s21_determinant(A, &detA);
    if (fabs(detA - 0) > 1e-6) {
      matrix_t tmp_minor = {0};
      result_code = s21_calc_complements(A, &tmp_minor);
      if (result_code == OK) {
        matrix_t tmp_transp = {0};
        result_code = s21_transpose(&tmp_minor, &tmp_transp);
        if (result_code == OK) {
          s21_mult_number(&tmp_transp, 1 / detA, result);
        } else {
          result_code = CALCULATION_ERROR;
        }
        s21_remove_matrix(&tmp_transp);
      } else {
        result_code = CALCULATION_ERROR;
      }
      s21_remove_matrix(&tmp_minor);
    } else {
      result_code = CALCULATION_ERROR;
    }
  }
  return result_code;
}