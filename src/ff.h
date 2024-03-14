#pragma once

#include <stdbool.h>
#include <stdint.h>

struct p_ff_poly {
  uint8_t p_ff;
  uint8_t deg;      // deg is always eq last non-zero index in ff_t
  uint8_t *coeffs;  // big endian x^2 + 2x + 3 -> {1,2,3}
};

typedef struct p_ff_poly *p_ff_poly_t;
typedef struct p_ff_poly *ff_t;

struct ff_elem {
  ff_t ff;
  uint8_t deg;
  uint8_t *coeffs;
};

typedef struct ff_elem *ff_elem_t;

ff_elem_t ff_create_elem(ff_t ff);

ff_elem_t ff_get_zero(ff_t ff);
ff_elem_t ff_get_identity(ff_t ff);

bool ff_are_eq(ff_t fst, ff_t snd);
bool ff_elems_are_eq(ff_elem_t fst, ff_elem_t snd);

ff_elem_t ff_add(ff_elem_t fst, ff_elem_t snd);
ff_elem_t ff_sub(ff_elem_t fst, ff_elem_t snd);
ff_elem_t ff_mult(ff_elem_t fst, ff_elem_t snd);
ff_elem_t ff_div(ff_elem_t fst, ff_elem_t snd);

ff_elem_t ff_inv_add(ff_elem_t elem);
ff_elem_t ff_inv_mult(ff_elem_t fst, ff_elem_t snd);

void p_ff_poly_free(p_ff_poly_t poly);
void ff_elem_free(ff_elem_t fst);
