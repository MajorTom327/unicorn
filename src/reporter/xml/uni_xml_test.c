#include <unicorn.h>
#include <stdio.h>

const char*uni_get_status_test(t_uni_test *test) {
  if (test->result == TEST_RESULT_OK) {
    return "passed";
  } else if (test->result == TEST_RESULT_FAIL) {
    return "failed";
  } else if (test->result == TEST_RESULT_SKIP) {
    return "skipped";
  }
  return "unknown";
}

int uni_xml_test(FILE *fd, t_uni_test *test) {
  fprintf(fd, "    <testcase name=\"%s\" status=\"%s\" />\n", test->name, uni_get_status_test(test));
  return 0;
}
