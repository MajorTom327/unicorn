#ifndef UNICORN_H
#define UNICORN_H

typedef enum e_test_result {
  TEST_RESULT_PENDING,
  TEST_RESULT_OK,
  TEST_RESULT_FAIL,
  TEST_RESULT_SKIP,
} t_test_result;

typedef struct s_uni_test {
  char *name;
  int (*func)();

  t_test_result result;
  struct s_uni_test *next;
} t_uni_test;

typedef struct s_uni_suite {
  char *name;

  t_uni_test *tests;
  struct s_unit_suite *next;
} t_uni_suite;

typedef struct s_uni_runner {
  t_uni_suite *suites;
} t_uni_runner;

// * Runner
t_uni_runner *uni_runner_new();

// * Suites
t_uni_suite *uni_suite_new(char *name);
t_uni_suite *uni_suite_add_test(t_uni_suite *suite, t_uni_test *test);

// * Tests
t_uni_test *uni_test_new(char *name, int (*func)());

#endif
