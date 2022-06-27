#include <unicorn.h>
#include <stdio.h>

t_uni_suite *uni_suite_add_test(t_uni_suite *suite, t_uni_test *test) {
  if (suite->tests == NULL) {
    suite->tests = test;
  } else {
    t_uni_test *current = suite->tests;
    while (current->next != NULL) {
      current = (t_uni_test *)current->next;
    }
    current->next = test;
  }

  return suite;
}
