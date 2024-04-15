#include <check.h>

#include "quadratic_equation.h"

START_TEST(test1) {
  double a = 1;
  double b = 1;
  double c = 1;

  Roots roots = solve_equation(a, b, c);
  ck_assert_double_nan(roots.x1);
  ck_assert_double_nan(roots.x2);
}
END_TEST

START_TEST(test2) {
  double a = 1;
  double b = 2;
  double c = 1;

  Roots roots = solve_equation(a, b, c);
  ck_assert_double_eq(roots.x1, -1);
  ck_assert_double_eq(roots.x2, -1);
}
END_TEST

START_TEST(test3) {
  double a = 1;
  double b = -2;
  double c = -3;

  Roots roots = solve_equation(a, b, c);
  ck_assert_double_eq(roots.x1, 3);
  ck_assert_double_eq(roots.x2, -1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test1);
  tcase_add_test(tc1_1, test2);
  tcase_add_test(tc1_1, test3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
