#include <unicorn.h>
#include <unistd.h>
#include <stdio.h>

int uni_xml_suite(FILE* fd, t_uni_suite *suite) {
  t_uni_test *current = suite->tests;
  fprintf(fd, "  <testsuite name=\"%s\">\n", suite->name);
  while (current != NULL) {
    uni_xml_test(fd, current);
    current = (t_uni_test *)current->next;
  }
  fprintf(fd, "  </testsuite>\n");
  return 0;
}
