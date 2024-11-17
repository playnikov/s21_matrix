#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0           //* ОК
#define UNCORRECTED 1  //* Ошибка, некорректная матрица
#define CALCULATION_ERROR 2  //* Ошибка вычисления

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// TODO: s21_matrix_advertisement
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// TODO: s21_matrix_arithmetic
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// TODO: s21_matrix_comparison
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// TODO: s21_matrix_components
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// TODO: s21_helper_func
int s21_matrix_empty(matrix_t *matrix);
void s21_get_matrix(matrix_t *A, matrix_t *result, int row, int column);
double s21_get_determinant(matrix_t *A);

#endif  // S21_MATRIX_H
