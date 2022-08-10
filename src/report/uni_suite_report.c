#include <unicorn.h>
#include <stdlib.h>

t_uni_report *uni_suite_report(t_uni_suite *suite) {
  t_uni_report *report = malloc(sizeof(t_uni_report));
  report->test_count = 0;
  report->test_passed = 0;
  report->test_failed = 0;
  t_uni_test *test = suite->tests;
  while (test != NULL) {
    report->test_count++;
    if (test->result == TEST_RESULT_OK) {
      report->test_passed++;
    } else if (test->result == TEST_RESULT_FAIL) {
      report->test_failed++;
    }
    test = test->next;
  }
  return report;
}
