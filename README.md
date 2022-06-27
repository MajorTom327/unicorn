# Unicorn

A basic C unit testing framework

## Badges

[![build](https://github.com/MajorTom327/unicorn/actions/workflows/build.yml/badge.svg)](https://github.com/MajorTom327/unicorn/actions/workflows/build.yml)
[![MIT License](https://img.shields.io/apm/l/atomic-design-ui.svg?)](https://github.com/tterb/atomic-design-ui/blob/master/LICENSEs)

## Features

- Group tests per suite
- Simple result


## Usage/Examples

`suite_isalpha.c`
```C
#include "test.h"
#include <libft.h>
#include <ctype.h>

int test_isalpha_a();
int test_isalpha_1();

t_uni_suite *suite_isalpha() {
  t_uni_suite *suite = uni_suite_new("isalpha");

  t_uni_test *t1 = uni_test_new("a shoud be alpha", &test_isalpha_a);
  t_uni_test *t2 = uni_test_new("1 shoud be alpha", &test_isalpha_1);

  uni_suite_add_test(suite, t1);
  uni_suite_add_test(suite, t2);
  return suite;
}

int test_isalpha_a() {
  return ft_isalpha('a') == isalpha('a'); // OK test
}

int test_isalpha_1() {
  return ft_isalpha('1') == isalpha('a'); // Fail test
}
```

`main.c`
```C
#include "test.h"
#include <unicorn.h>

int main(void)
{
  t_uni_runner *runner = uni_runner_new();
  uni_runner_add_suite(runner, suite_isalpha());
  uni_runner_run(runner);
  uni_view_result(runner);
}
```
