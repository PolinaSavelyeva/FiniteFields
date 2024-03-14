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

struct p_ff_poly ff_3_8 = {.p_ff = 3, .deg = 8, .coeffs = irr_poly_8};

// x^16 + x^12 + x^7 + x^2 + 1
uint8_t irr_poly_16[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1};
struct p_ff_poly ff_11_16 = {.p_ff = 11, .deg = 16, .coeffs = irr_poly_16};

MU_TEST(get_zero_ff_2_2) {
  ff_elem_t actual = ff_get_zero(&ff_2_2);
  uint8_t zero[] = {0, 0};
  struct ff_elem expected = {.ff = &ff_2_2, .deg = 1, .coeffs = zero};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST(get_zero_ff_2_4) {
  ff_elem_t actual = ff_get_zero(&ff_2_4);
  uint8_t zero[] = {0, 0, 0, 0};
  struct ff_elem expected = {.ff = &ff_2_4, .deg = 3, .coeffs = zero};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST(get_zero_ff_2_8) {
  ff_elem_t actual = ff_get_zero(&ff_2_8);
  uint8_t zero[] = {0, 0, 0, 0, 0, 0, 0, 0};
  struct ff_elem expected = {.ff = &ff_2_8, .deg = 7, .coeffs = zero};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST_SUITE(get_zero_tests) {
  MU_RUN_TEST(get_zero_ff_2_2);
  MU_RUN_TEST(get_zero_ff_2_4);
  MU_RUN_TEST(get_zero_ff_2_8);
}

MU_TEST(get_identity_ff_2_2) {
  ff_elem_t actual = ff_get_identity(&ff_2_2);
  uint8_t identity[] = {0, 1};
  struct ff_elem expected = {.ff = &ff_2_2, .deg = 1, .coeffs = identity};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST(get_identity_ff_2_4) {
  ff_elem_t actual = ff_get_identity(&ff_2_4);
  uint8_t identity[] = {0, 0, 0, 1};
  struct ff_elem expected = {.ff = &ff_2_4, .deg = 3, .coeffs = identity};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST(get_identity_ff_2_8) {
  ff_elem_t actual = ff_get_identity(&ff_2_8);
  uint8_t identity[] = {0, 0, 0, 0, 0, 0, 0, 1};
  struct ff_elem expected = {.ff = &ff_2_8, .deg = 7, .coeffs = identity};
  bool are_eq = ff_elems_are_eq(actual, &expected);

  ff_elem_free(actual);

  mu_check(are_eq);
}

MU_TEST_SUITE(get_identity_tests) {
  MU_RUN_TEST(get_identity_ff_2_2);
  MU_RUN_TEST(get_identity_ff_2_4);
  MU_RUN_TEST(get_identity_ff_2_8);
}

MU_TEST(add_zeros_ff_2_2) {
  ff_elem_t zero = ff_get_zero(&ff_2_2);
  ff_elem_t add_res = ff_add(zero, zero);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);

  mu_check(are_eq);
}

MU_TEST(add_zeros_ff_2_4) {
  ff_elem_t zero = ff_get_zero(&ff_2_4);
  ff_elem_t add_res = ff_add(zero, zero);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);

  mu_check(are_eq);
}

MU_TEST(add_zeros_ff_2_8) {
  ff_elem_t zero = ff_get_zero(&ff_2_8);
  ff_elem_t add_res = ff_add(zero, zero);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);

  mu_check(are_eq);
}

MU_TEST(add_identities_ff_2_2) {
  ff_elem_t identity = ff_get_identity(&ff_2_2);
  ff_elem_t add_res = ff_add(identity, identity);
  ff_elem_t zero = ff_get_zero(&ff_2_2);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);
  ff_elem_free(identity);

  mu_check(are_eq);
}

MU_TEST(add_identities_ff_2_4) {
  ff_elem_t identity = ff_get_identity(&ff_2_4);
  ff_elem_t add_res = ff_add(identity, identity);
  ff_elem_t zero = ff_get_zero(&ff_2_4);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);
  ff_elem_free(identity);

  mu_check(are_eq);
}

MU_TEST(add_identities_ff_2_8) {
  ff_elem_t identity = ff_get_identity(&ff_2_8);
  ff_elem_t add_res = ff_add(identity, identity);
  ff_elem_t zero = ff_get_zero(&ff_2_8);
  bool are_eq = ff_elems_are_eq(add_res, zero);

  ff_elem_free(add_res);
  ff_elem_free(zero);
  ff_elem_free(identity);

  mu_check(are_eq);
}

MU_TEST(add_identities_ff_3_8) {
  ff_elem_t identity = ff_get_identity(&ff_3_8);
  ff_elem_t add_res = ff_add(identity, identity);

  uint8_t expected_coeffs[] = {0, 0, 0, 0, 0, 0, 0, 2};
  struct ff_elem expected = {
      .ff = &ff_3_8, .deg = 7, .coeffs = expected_coeffs};
  bool are_eq = ff_elems_are_eq(add_res, &expected);

  ff_elem_free(add_res);
  ff_elem_free(identity);

  mu_check(are_eq);
}

MU_TEST(add_special_ff_3_8) {
  uint8_t fst_coeffs[] = {1, 1, 2, 2, 0, 1, 1, 2};
  struct ff_elem fst = {.ff = &ff_3_8, .deg = 7, .coeffs = fst_coeffs};

  uint8_t snd_coeffs[] = {1, 1, 0, 0, 2, 2, 1, 0};
  struct ff_elem snd = {.ff = &ff_3_8, .deg = 7, .coeffs = snd_coeffs};

  uint8_t expected_coeffs[] = {2, 2, 2, 2, 2, 0, 2, 2};
  struct ff_elem expected = {
      .ff = &ff_3_8, .deg = 7, .coeffs = expected_coeffs};

  ff_elem_t add_res = ff_add(&fst, &snd);

  bool are_eq = ff_elems_are_eq(add_res, &expected);

  ff_elem_free(add_res);

  mu_check(are_eq);
}

MU_TEST(add_special_ff_2_8) {
  uint8_t fst_coeffs[] = {1, 1, 1, 1, 1, 1, 1, 1};
  struct ff_elem fst = {.ff = &ff_2_8, .deg = 7, .coeffs = fst_coeffs};

  uint8_t snd_coeffs[] = {0, 1, 1, 1, 1, 1, 1, 0};
  struct ff_elem snd = {.ff = &ff_2_8, .deg = 7, .coeffs = snd_coeffs};

  uint8_t expected_coeffs[] = {1, 0, 0, 0, 0, 0, 0, 1};
  struct ff_elem expected = {
      .ff = &ff_2_8, .deg = 7, .coeffs = expected_coeffs};

  ff_elem_t add_res = ff_add(&fst, &snd);

  bool are_eq = ff_elems_are_eq(add_res, &expected);

  ff_elem_free(add_res);

  mu_check(are_eq);
}

MU_TEST(add_special_ff_11_16) {
  uint8_t fst_coeffs[] = {9, 8, 0, 2, 3, 4, 1, 0, 1, 4, 2, 1, 0, 7, 2, 10};
  struct ff_elem fst = {.ff = &ff_11_16, .deg = 15, .coeffs = fst_coeffs};

  uint8_t snd_coeffs[] = {0, 1, 2, 3, 4, 10, 9, 3, 9, 5, 3, 4, 1, 9, 3, 4};
  struct ff_elem snd = {.ff = &ff_11_16, .deg = 15, .coeffs = snd_coeffs};

  uint8_t expected_coeffs[] = {9,  9, 2, 5, 7, 3, 10, 3,
                               10, 9, 5, 5, 1, 5, 5,  3};
  struct ff_elem expected = {
      .ff = &ff_11_16, .deg = 15, .coeffs = expected_coeffs};

  ff_elem_t add_res = ff_add(&fst, &snd);

  bool are_eq = ff_elems_are_eq(add_res, &expected);

  ff_elem_free(add_res);

  mu_check(are_eq);
}

MU_TEST_SUITE(add_tests) {
  MU_RUN_TEST(add_zeros_ff_2_2);
  MU_RUN_TEST(add_zeros_ff_2_4);
  MU_RUN_TEST(add_zeros_ff_2_8);
  MU_RUN_TEST(add_identities_ff_2_2);
  MU_RUN_TEST(add_identities_ff_2_4);
  MU_RUN_TEST(add_identities_ff_2_8);
  MU_RUN_TEST(add_identities_ff_3_8);
  MU_RUN_TEST(add_special_ff_3_8);
  MU_RUN_TEST(add_special_ff_2_8);
  MU_RUN_TEST(add_special_ff_11_16);
}

MU_TEST(inv_add_special_ff_2_4) {
  uint8_t coeffs[] = {1, 0, 1, 1};
  struct ff_elem elem = {.ff = &ff_2_4, .deg = 3, .coeffs = coeffs};
  ff_elem_t inv = ff_inv_add(&elem);
  bool are_eq = ff_elems_are_eq(inv, &elem);
  ff_elem_free(inv);

  mu_check(are_eq);
}

MU_TEST(inv_add_special_ff_2_8) {
  uint8_t coeffs[] = {1, 0, 0, 1, 0, 0, 1, 1};
  struct ff_elem elem = {.ff = &ff_2_8, .deg = 7, .coeffs = coeffs};

  ff_elem_t inv = ff_inv_add(&elem);
  ff_elem_t add = ff_add(&elem, inv);
  ff_elem_t zero = ff_get_zero(&ff_2_8);

  bool are_eq = ff_elems_are_eq(zero, add);

  ff_elem_free(inv);
  ff_elem_free(add);
  ff_elem_free(zero);

  mu_check(are_eq);
}

MU_TEST(inv_add_special_ff_11_16) {
  uint8_t coeffs[] = {9, 8, 0, 2, 3, 4, 1, 0, 1, 4, 2, 1, 0, 7, 2, 10};
  struct ff_elem elem = {.ff = &ff_11_16, .deg = 15, .coeffs = coeffs};

  ff_elem_t inv = ff_inv_add(&elem);
  ff_elem_t add = ff_add(&elem, inv);
  ff_elem_t zero = ff_get_zero(&ff_11_16);

  bool are_eq = ff_elems_are_eq(zero, add);

  ff_elem_free(inv);
  ff_elem_free(add);
  ff_elem_free(zero);

  mu_check(are_eq);
}

MU_TEST_SUITE(inv_add_tests) {
  MU_RUN_TEST(inv_add_special_ff_2_4);
  MU_RUN_TEST(inv_add_special_ff_2_8);
  MU_RUN_TEST(inv_add_special_ff_11_16);
}

MU_TEST(sub_special_ff_11_16) {
  uint8_t fst_coeffs[] = {9, 8, 0, 2, 3, 4, 1, 0, 1, 4, 2, 1, 0, 7, 2, 10};
  struct ff_elem fst = {.ff = &ff_11_16, .deg = 15, .coeffs = fst_coeffs};

  uint8_t snd_coeffs[] = {0, 1, 2, 3, 4, 10, 9, 3, 9, 5, 3, 4, 1, 9, 3, 4};
  struct ff_elem snd = {.ff = &ff_11_16, .deg = 15, .coeffs = snd_coeffs};

  uint8_t expected_coeffs[] = {9, 7,  9,  10, 10, 5, 3,  8,
                               3, 10, 10, 8,  10, 9, 10, 6};
  struct ff_elem expected = {
      .ff = &ff_11_16, .deg = 15, .coeffs = expected_coeffs};

  ff_elem_t sub_res = ff_sub(&fst, &snd);

  bool are_eq = ff_elems_are_eq(sub_res, &expected);

  ff_elem_free(sub_res);

  mu_check(are_eq);
}

MU_TEST_SUITE(sub_tests) { MU_RUN_TEST(sub_special_ff_11_16); }

int main() {
  MU_RUN_SUITE(get_zero_tests);
  MU_RUN_SUITE(get_identity_tests);
  MU_RUN_SUITE(add_tests);
  MU_RUN_SUITE(inv_add_tests);
  MU_RUN_SUITE(sub_tests);
  MU_REPORT();
  return MU_EXIT_CODE;
}
