#include <unicorn.h>
#include <stdlib.h>

t_uni_runner *uni_runner_add_suite(t_uni_runner *runner, t_uni_suite *suite) {
  if (runner->suites == NULL) {
    runner->suites = suite;
  } else {
    t_uni_suite *current = runner->suites;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = suite;
  }
  return runner;
}
