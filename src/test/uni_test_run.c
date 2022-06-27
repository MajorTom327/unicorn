#include <unicorn.h>
#include <stdlib.h>

int uni_test_run(t_uni_test *test) {
  test->result = TEST_RESULT_PENDING;

  const int result = test->func();
  if (result == 1) {
    test->result = TEST_RESULT_OK;
  } else {
    test->result = TEST_RESULT_FAIL;
  }
  return result;
}
