#ifndef UNICORN_H
#define UNICORN_H

#include <stdio.h>

typedef enum e_test_result {
  TEST_RESULT_PENDING,
  TEST_RESULT_OK,
  TEST_RESULT_FAIL,
  TEST_RESULT_SKIP,
} t_test_result;

typedef struct s_uni_test {
  char *name;
  unsigned long duration;
  int (*func)();

  t_test_result result;
  struct s_uni_test *next;
} t_uni_test;

typedef struct s_uni_suite {
  char *name;

  t_uni_test *tests;
  struct s_uni_suite *next;
} t_uni_suite;

typedef struct s_uni_runner {
  t_uni_suite *suites;
} t_uni_runner;

// * Runner
t_uni_runner *uni_runner_add_suite(t_uni_runner *runner, t_uni_suite *suite);
t_uni_runner *uni_runner_new();
int uni_runner_run(t_uni_runner *runner);

// * Suites
t_uni_suite *uni_suite_new(char *name);
t_uni_suite *uni_suite_add_test(t_uni_suite *suite, t_uni_test *test);
int uni_suite_run(t_uni_suite *suite);

// * Tests
t_uni_test *uni_test_new(char *name, int (*func)());
int uni_test_run(t_uni_test *test);

// * View
void uni_view_result(const t_uni_runner *runner);

// * Reporter
int uni_xml_reporter(const char *filepath, t_uni_runner *runner);
int uni_xml_suite(FILE* fd, t_uni_suite *suite);
int uni_xml_test(FILE* fd, t_uni_test *test);


#endif
