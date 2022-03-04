#include "../include/mympfr.h"

mpfr_prec_t digits2bits(uint64_t d)
{
    const double LOG2_10 = 3.3219280948873624;

    return (mpfr_prec_t) ceil( d * LOG2_10 );
}

int bits2digits(mp_prec_t b)
{
    const double LOG10_2 = 0.30102999566398119;

    return (int)floor( b * LOG10_2 );
}

mpfr_t *allocate_mpfr_1D_vector(size_t n, uint64_t nDigits)
{
  /* ALLOCATE_MPFR_1D_VECTOR: allocates memory for a multiple mpfr_t
   * precision vector of n components
   * n:      number of components v[0],...,v[n-1]
   * nDgits: number of significat digits for each component         */

  mpfr_t *v;
  mpfr_prec_t prec;

  v = (mpfr_t *)calloc((size_t)(n), sizeof(mpfr_t));
  if (!v) {
    fprintf(stderr, "allocate_mpfr_1D_vector:\n");
    fprintf(stderr, "Error. Can't allocate memory for the vector\n");
    exit(EXIT_FAILURE);
  }

  prec = digits2bits(nDigits);

  for (uint64_t i=0; i<n; i++) 
     mpfr_init2(v[i], prec);

  return v; /* Returns the pointer to the 1st element of the vector */
}

void free_mpfr_1D_vector(mpfr_t *v, size_t n)
{
  /* FREE_MPFR_1D_VECTOR: deallocates the memory for a multiple mpfr_t
   * precision vector of n components                               */

  for (size_t i = 0; i < n; i++)
    mpfr_clear(v[i]);

  free((char *) (v));
}
