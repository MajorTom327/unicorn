#include <unicorn.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Get the number of failed tests
 * @param runner The runner
 * @return The number of failed tests
 */
int uni_get_final_result(const t_uni_runner *runner) {
  t_uni_suite *current = runner->suites;
  int failed = 0;

  while (current != NULL) {
    t_uni_test *test = current->tests;
    while (test != NULL) {
      if (test->result == TEST_RESULT_FAIL) {
        failed++;
      }
      test = test->next;
    }
    current = current->next;
  }

  return failed;
}
