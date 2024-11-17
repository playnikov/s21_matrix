#include "tests/s21_matrix_tests.h"

int main(void) {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests() {
  int counter_testcase = 1;

  Suite *list_cases[] = {create_matrix_suite(), suite_comparison_matrix(),
                         suite_arithmetic_matrix(), suite_components_matrix(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase, counter_testcase);
    counter_testcase++;
  }
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}