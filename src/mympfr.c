#include "../include/mympfr.h"

mpfr_prec_t digits2bits(int d)
{
    const double LOG2_10 = 3.3219280948873624;

    return (mpfr_prec_t) ceil( d * LOG2_10 );
}

int bits2digits(mp_prec_t b)
{
    const double LOG10_2 = 0.30102999566398119;

    return (int)floor( b * LOG10_2 );
}

mpfr_t *allocate_mpfr_1D_vector(uint64_t n)
{
  /* ALLOCATE_MPFR_1D_VECTOR: allocates memory for a multiple mpfr_t
   * precision of n components                                      */
  mpfr_t *v;
  v = (mpfr_t *)calloc((size_t)(n), sizeof(mpfr_t));
  if (!v) {
    fprintf(stderr, "allocate_mpfr_1D_vector:\n");
    fprintf(stderr, "Error. Can't allocate memory for the vector\n");
    exit(EXIT_FAILURE);
  }

  return v; /* Returns the pointer to the 1st element of the vector */
}

void free_mpfr_1D_vector(mpfr_t *v)
{
  free((char *) (v));
}
