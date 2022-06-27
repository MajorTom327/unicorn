#include <unicorn.h>
#include <stdio.h>
#include <stdlib.h>

t_uni_suite *uni_suite_new(char *name) {
  t_uni_suite *suite = malloc(sizeof(t_uni_suite));
  suite->name = name;
  suite->tests = NULL;
  return suite;
}
