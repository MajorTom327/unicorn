#include <unicorn.h>
#include <unistd.h>
#include <stdio.h>

int uni_xml_reporter(const char *filepath, t_uni_runner *runner) {
  FILE *file = fopen(filepath, "w");
  if (file == NULL) {
    return -1;
  }
  fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(file, "<testsuites>\n");
  t_uni_suite *current = runner->suites;
  while (current != NULL) {
    uni_xml_suite(file, current);
    current = (t_uni_suite *)current->next;
  }
  fprintf(file, "</testsuites>\n");
  fclose(file);
  return 0;
}
