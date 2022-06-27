#include <unicorn.h>
#include <stdlib.h>

int uni_runner_run(t_uni_runner *runner) {
  t_uni_suite *current = runner->suites;
  while (current != NULL) {
    uni_suite_run(current);
    current = (t_uni_suite *)current->next;
  }

  return 0;

}
