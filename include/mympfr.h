#ifndef _MPFR_TEST_1_H
#define _MPFR_TEST_1_H

#include<mpfr.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

mpfr_prec_t digits2bits(int d);
int bits2digits(mpfr_prec_t b);
mpfr_t *allocate_mpfr_1D_vector(uint64_t);
void free_mpfr_1D_vector(mpfr_t *);

#endif  // _MPFR_TEST_1_H
