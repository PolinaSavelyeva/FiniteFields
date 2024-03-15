#include "ff.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

ff_elem_t ff_create_elem(ff_t ff) {
  ff_elem_t elem = malloc(sizeof(struct ff_elem));
  elem->ff = ff;
  elem->deg = ff->deg - 1;
  elem->coeffs = calloc(ff->deg, 1);

  return elem;
}

ff_elem_t ff_init_elem(ff_t ff, uint8_t *coeffs) {
  ff_elem_t elem = malloc(sizeof(struct ff_elem));
  elem->ff = ff;
  elem->deg = ff->deg - 1;
  elem->coeffs = coeffs;

  return elem;
}

ff_elem_t ff_get_zero(ff_t ff) { return ff_create_elem(ff); }

ff_elem_t ff_get_identity(ff_t ff) {
  ff_elem_t identity = ff_create_elem(ff);
  identity->coeffs[identity->deg] = 1;

  return identity;
}

bool ff_are_eq(ff_t fst, ff_t snd) {
  return (fst->p_ff == snd->p_ff && fst->deg == snd->deg &&
          !memcmp(fst->coeffs, snd->coeffs, (fst->deg + 1)));
}

bool ff_elems_are_eq(ff_elem_t fst, ff_elem_t snd) {
  return (fst->ff == snd->ff && fst->deg == snd->deg &&
          !memcmp(fst->coeffs, snd->coeffs, fst->deg + 1));
}

ff_elem_t ff_add(ff_elem_t fst, ff_elem_t snd) {
  if (!ff_are_eq(fst->ff, snd->ff)) return NULL;

  ff_elem_t res = ff_create_elem(fst->ff);

  for (uint8_t i = 0; i < res->deg + 1; i++) {
    res->coeffs[i] = (fst->coeffs[i] + snd->coeffs[i]) % fst->ff->p_ff;
  }

  return res;
}

ff_elem_t ff_inv_add(ff_elem_t elem) {
  ff_elem_t res = ff_create_elem(elem->ff);

  for (uint8_t i = 0; i < res->deg + 1; i++) {
    res->coeffs[i] = (elem->ff->p_ff - elem->coeffs[i]) % elem->ff->p_ff;
  }

  return res;
}

void p_ff_poly_free(p_ff_poly_t poly) {
  free(poly->coeffs);
  free(poly);
}

void ff_elem_free(ff_elem_t fst) {
  free(fst->coeffs);
  free(fst);
}

ff_elem_t ff_sub(ff_elem_t fst, ff_elem_t snd) {
  ff_elem_t inv_snd = ff_inv_add(snd);
  ff_elem_t res = ff_add(fst, inv_snd);
  ff_elem_free(inv_snd);

  return res;
}

// Return the index of the first non-zero element of polynomial
// If all elements are 0 returns -1
static int real_deg(uint8_t deg, uint8_t *coeffs) {
  for (uint8_t i = 0; i <= deg; i++) {
    if (coeffs[i]) return deg - i;
  }

  return -1;
}

ff_elem_t ff_mult(ff_elem_t fst, ff_elem_t snd) {
  if (!ff_are_eq(fst->ff, snd->ff)) return NULL;

  uint8_t mult_deg = 2 * fst->deg;
  uint8_t *coeffs = calloc(mult_deg + 1, 1);

  for (uint8_t i = 0; i <= fst->deg; i++) {
    for (uint8_t j = 0; j <= snd->deg; j++) {
      coeffs[i + j] =
          (coeffs[i + j] + fst->coeffs[i] * snd->coeffs[j]) % fst->ff->p_ff;
    }
  }

  int real_deg_res = real_deg(mult_deg, coeffs);

  for (uint8_t i = mult_deg - real_deg_res; i <= mult_deg - fst->ff->deg; i++) {
    uint8_t q = pow(fst->ff->coeffs[0], fst->ff->p_ff - 2) * fst->coeffs[i];
    for (uint8_t j = 0; j <= fst->ff->deg; j++) {
      int16_t tmp =
          ((int16_t)coeffs[i + j] - (int16_t)(q * fst->ff->coeffs[j])) %
          fst->ff->p_ff;
      coeffs[i + j] = tmp >= 0 ? tmp : tmp + fst->ff->p_ff;
    }
  }

  ff_elem_t res = ff_create_elem(fst->ff);
  memcpy(res->coeffs, coeffs + fst->deg, fst->deg + 1);
  free(coeffs);

  return res;
}
