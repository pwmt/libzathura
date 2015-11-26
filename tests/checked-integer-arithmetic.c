/* See LICENSE file for license and copyright information */

#include <check.h>
#include <stdint.h>
#include <limits.h>

#include "checked-integer-arithmetic.h"

START_TEST(test_checked_integer_arithmetic_umul) {
  unsigned int res = 0;
  fail_unless(checked_umul(1, 1, &res) == false);
  fail_unless(res == 1);

  fail_unless(checked_umul(UINT_MAX, UINT_MAX, &res) == true);
} END_TEST

Suite*
suite_checked_integer_arithmetic(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("checked-integer-arithmetic");

  tcase = tcase_create("unsigned int");
  tcase_add_test(tcase, test_checked_integer_arithmetic_umul);
  suite_add_tcase(suite, tcase);

  return suite;
}
