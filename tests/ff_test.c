#include "ff.h"

#include <stdbool.h>
#include <stdlib.h>

#include "minunit.h"

uint8_t irr_poly_2[] = {1, 1, 1};
struct p_ff_poly ff_2_2 = {.p_ff = 2, .deg = 2, .coeffs = irr_poly_2};

uint8_t irr_poly_4[] = {1, 0, 0, 1, 1};
struct p_ff_poly ff_2_4 = {.p_ff = 2, .deg = 4, .coeffs = irr_poly_4};

uint8_t irr_poly_8[] = {1, 0, 0, 0, 1, 1, 1, 0, 1};
struct p_ff_poly ff_2_8 = {.p_ff = 2, .deg = 8, .coeffs = irr_poly_8};

static void test_get_zero(ff_t ff) {
  int deg = ff->deg;
  ff_elem_t actual = ff_get_zero(ff);
  uint8_t zero[deg];

  for (int i = 0; i < deg; i++) zero[i] = 0;

  struct ff_elem expected = {.ff = ff, .deg = deg - 1, .coeffs = zero};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);
  mu_check(are_eq);
}

MU_TEST(get_zero_ff_2_2) { test_get_zero(&ff_2_2); }

MU_TEST(get_zero_ff_2_4) { test_get_zero(&ff_2_4); }

MU_TEST(get_zero_ff_2_8) { test_get_zero(&ff_2_8); }

MU_TEST_SUITE(get_zero_tests) {
  MU_RUN_TEST(get_zero_ff_2_2);
  MU_RUN_TEST(get_zero_ff_2_4);
  MU_RUN_TEST(get_zero_ff_2_8);
}

int main() {
  MU_RUN_SUITE(get_zero_tests);
  MU_REPORT();
  return MU_EXIT_CODE;
}
