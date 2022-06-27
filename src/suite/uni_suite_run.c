#include <unicorn.h>
#include <stdlib.h>

int uni_suite_run(t_uni_suite *suite) {
  t_uni_test *current = suite->tests;
  while (current != NULL) {
    uni_test_run(current);
    current = (t_uni_test *)current->next;
  }
  return 0;
}
