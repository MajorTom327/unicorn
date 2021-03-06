#include <unicorn.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned long uni_get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (1000000 * tv.tv_sec + tv.tv_usec);
}

int uni_suite_run(t_uni_suite *suite) {
  t_uni_test *current = suite->tests;
  unsigned long suite_start = uni_get_time();
  while (current != NULL) {
    unsigned long start = uni_get_time();
    uni_test_run(current);
    current->duration = uni_get_time() - start;
    current = (t_uni_test *)current->next;
  }
  suite->duration = uni_get_time() - suite_start;
  return 0;
}
