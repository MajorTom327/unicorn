# Unicorn

A basic C unit testing framework

## Badges

[![build](https://github.com/MajorTom327/unicorn/actions/workflows/build.yml/badge.svg)](https://github.com/MajorTom327/unicorn/actions/workflows/build.yml)
[![MIT License](https://img.shields.io/apm/l/atomic-design-ui.svg?)](https://github.com/tterb/atomic-design-ui/blob/master/LICENSEs)

## Features

- Group tests per suite
- Simple result

## Build

```bash
make
```


## Usage/Examples

You can find a implementation on the repository [libft-reborn](https://github.com/MajorTom327/libft-reborn)

> suite_isalpha.c
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

> main.c
```C
#include "test.h"
#include <unicorn.h>

int main(void)
{
  t_uni_runner *runner = uni_runner_new();
  uni_runner_add_suite(runner, suite_isalpha());
  uni_runner_run(runner);
  uni_view_result(runner); // View the result in the console
  uni_xml_reporter("./test.xml", runner); // Create a XML report
}
```

The executable result should look like this:
![result](screen/result.png)

You have to link the librairie to your test project.

In the exemple case, the projet tree look like this:
```
libft
|_ Makefile
|_ src
| |_ ft_isalpha.c
|_ include
| |_ libft.h
|_ tests
  |_ Makefile
  |_ unicorn
  | |_ libunicorn.a
  | |_ include
  |   |_ unicorn.h
  |_ src
  | |_ suite_isalpha.c
  | |_ main.c
  |_ include
    |_ test.h
```

- The libft's Makefile only build the libft.a
- The tests's Makefile build a executable for testing the lib

## XML Report
You can add a XML report of the testsBy adding a call to the xml export function

```C
uni_xml_reporter("./test.xml", runner);
```

```xml
<?xml version="1.0" encoding="UTF-8"?>
<testsuites>
  <testsuite name="isalpha" duration="1">
    <testcase name="a shoud be alpha" status="passed" duration="1" />
    <testcase name="1 shoud be alpha" status="failed" duration="0" />
  </testsuite>
</testsuites>

```
