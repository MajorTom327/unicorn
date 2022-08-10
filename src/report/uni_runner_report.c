#include <unicorn.h>
#include <stdlib.h>

t_uni_report *uni_runner_report(t_uni_runner *runner) {
  t_uni_report *report = malloc(sizeof(t_uni_report));
  report->test_count = 0;
  report->test_passed = 0;
  report->test_failed = 0;
  t_uni_suite *suite = runner->suites;
  while (suite != NULL) {
    t_uni_report *suite_report = uni_suite_report(suite);
    report->test_count += suite_report->test_count;
    report->test_passed += suite_report->test_passed;
    report->test_failed += suite_report->test_failed;

    free(suite_report);
    suite = suite->next;
  }
  return report;
}
