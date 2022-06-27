#include <unicorn.h>
#include <stdio.h>
#include <stdlib.h>

t_uni_test *uni_test_new(char *name, int (*func)()) {
  t_uni_test *test = malloc(sizeof(t_uni_test));
  test->name = name;
  test->func = func;
  test->result = TEST_RESULT_PENDING;
  test->next = NULL;
  return test;
}
