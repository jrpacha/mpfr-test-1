#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "../include/mympfr.h"

#ifndef MAX
#define MAX 30
#endif

int main()
{
  char str[5];
  char fmt[MAX];

  int inex, numberOfDigits;
  uint64_t n = 10;
  mpfr_prec_t prec;
  mpfr_t *x;

  x = allocate_mpfr_1D_vector(n);

  fprintf(stdout, "Precision (digits): ");
  fscanf(stdin, "%d",&numberOfDigits);
  prec = digits2bits(numberOfDigits);

  sprintf(str,"%d",numberOfDigits);
  strcpy(fmt, "x(%d) = %.");
  strcat(fmt, str);
  strcat(fmt, "Re\n");

  mpfr_printf("For %d digits we need %d bytes\n",
      numberOfDigits, prec);
  fprintf(stdout,"Output string format: %s\n",fmt);
    
  for (uint64_t i=0; i < n; i++) {
    mpfr_init2(x[i], prec);
    inex = mpfr_set_ui(x[i], i, MPFR_RNDN);
    assert(inex == 0);
    mpfr_printf(fmt,i,x[i]);
    mpfr_clear(x[i]);
  }

  free_mpfr_1D_vector(x);
  mpfr_free_cache();

  return 0;
}
