# Matrix на языке C

Реализация библиотеки matrix.h.

> Запуск *make*


Реализация структуры матрицы:
```c
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;
```

Код ошибок:
```c
#define OK 0           //* ОК
#define UNCORRECTED 1  //* Ошибка, некорректная матрица
#define CALCULATION_ERROR 2  //* Ошибка вычисления
```

Создание и удаление матрицы:
```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
```

Арифметические функции:
```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

Проверка равенства матрицы:
```c
int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

Действия над матрицей:
```c
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

Вспомогательные функции:
```c
int s21_matrix_empty(matrix_t *matrix);
void s21_get_matrix(matrix_t *A, matrix_t *result, int row, int column);
double s21_get_determinant(matrix_t *A);
```