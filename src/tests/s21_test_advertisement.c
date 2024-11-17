#include "s21_matrix_tests.h"

START_TEST(s21_matrix_test_create_1) {
  matrix_t A;
  int rows = -1;
  int colums = 2;

  int result = s21_create_matrix(rows, colums, &A);
  ck_assert_int_eq(result, UNCORRECTED);
}
END_TEST

START_TEST(s21_matrix_test_create_2) {
  matrix_t A;
  int rows = 10;
  int colums = -2;

  int result = s21_create_matrix(rows, colums, &A);
  ck_assert_int_eq(result, UNCORRECTED);
}
END_TEST

START_TEST(s21_matrix_test_create_3) {
  matrix_t A;
  int rows = 10;
  int colums = 10;

  int result = s21_create_matrix(rows, colums, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(rows, A.rows);
  ck_assert_int_eq(colums, A.columns);

  if (A.matrix) {
    s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(s21_matrix_test_create_4) {
  matrix_t A;
  int rows = 2500;
  int colums = 10;

  int result = s21_create_matrix(rows, colums, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(rows, A.rows);
  ck_assert_int_eq(colums, A.columns);

  if (A.matrix) {
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite* create_matrix_suite() {
  Suite* suite = suite_create("suite_s21_create_matrix");
  TCase* tcase = tcase_create("tcase_s21_create_matrix");

  tcase_add_test(tcase, s21_matrix_test_create_1);
  tcase_add_test(tcase, s21_matrix_test_create_2);
  tcase_add_test(tcase, s21_matrix_test_create_3);
  tcase_add_test(tcase, s21_matrix_test_create_4);

  suite_add_tcase(suite, tcase);
  return suite;
}