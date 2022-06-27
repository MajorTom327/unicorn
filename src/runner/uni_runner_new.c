#include <unicorn.h>
#include <stdlib.h>

t_uni_runner *uni_runner_new() {
  t_uni_runner *runner = malloc(sizeof(t_uni_runner));

  return runner;
}
