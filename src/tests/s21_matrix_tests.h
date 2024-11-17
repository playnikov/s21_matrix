#ifndef S21_MATRIX_TESTS_H_
#define S21_MATRIX_TESTS_H_

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_matrix.h"

// TODO: tests create matrix
Suite* create_matrix_suite();

// TODO: tests arithmetic matrix
Suite* suite_arithmetic_matrix();

// TODO: tests comparison matrix
Suite* suite_comparison_matrix();

// TODO: tests matrix components
Suite* suite_components_matrix();

void run_tests(void);
void run_testcase(Suite* testcase, int counter_testcase);
double get_rand(double min, double max);

#endif  // S21_MATRIX_TESTS_H_