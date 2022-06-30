#include <unicorn.h>
#include <stdio.h>
#include <stdlib.h>

void uni_view_suite(const t_uni_suite *suite);
void uni_view_test(const t_uni_test *test);
const char  *uni_test_result_to_string(t_test_result result);
char *uni_test_duration_to_string(unsigned long duration);

void uni_view_result(const t_uni_runner *runner) {
  t_uni_suite *current = runner->suites;
  while (current != NULL) {
    uni_view_suite(current);
    current = (t_uni_suite *)current->next;
  }
}

void uni_view_suite(const t_uni_suite *suite) {
  t_uni_test *current = suite->tests;
  printf("📦 \033[1;4m%s:\033[0m\n", suite->name);
  while (current != NULL) {
    uni_view_test(current);
    current = (t_uni_test *)current->next;
  }
  printf("\n");
}

void uni_view_test(const t_uni_test *test) {
  int color;

  switch (test->result) {
    case TEST_RESULT_OK:
      color = 32;
      break;
    case TEST_RESULT_FAIL:
      color = 31;
      break;
    case TEST_RESULT_PENDING:
      color = 33;
      break;
    default:
      color = 37;
      break;
  }
  printf("  \033[%dm⚡️ %s:\033[0m %s %s\n",
    color,
    test->name,
    uni_test_result_to_string(test->result),
    uni_test_duration_to_string(test->duration)
  );
}

const char  *uni_test_result_to_string(t_test_result result) {
  switch (result) {
    case TEST_RESULT_PENDING:
      return "\033[33mPENDING\033[0m";
    case TEST_RESULT_OK:
      return "✅";
    case TEST_RESULT_FAIL:
      return "💥";
    case TEST_RESULT_SKIP:
      return "\033[90mSKIP\033[0m";
    default:
      return "\033[34mUNKNOWN\033[0m";
  }
}

char *uni_test_duration_to_string(unsigned long duration) {
  char *s = NULL;
  if (duration < 100L) {
    asprintf(&s, "\033[32m(%lu ms)\033[0m", duration);
  } else if (duration < 500L) {
    asprintf(&s, "\033[33m(%lu ms)\033[0m", duration);
  } else {
    asprintf(&s, "\033[31m(%lu ms)\033[0m", duration);
  }
  return s;
}
