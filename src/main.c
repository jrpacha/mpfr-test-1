#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "../include/mympfr.h"

#ifndef MAX
#define MAX 30
#endif

int main(int argc, char *argv[])
{
  char str[5];
  char inex, fmt[MAX];
  unsigned int numberOfDigits;

  if (argc != 2) {
    fprintf(stderr, "\nError: you must give the number of digits. Use\n");
    fprintf(stderr, "\t%s number_of_digits\n", argv[0]);
    exit(EXIT_FAILURE);
  } else {
    numberOfDigits = (unsigned int) atoi(argv[1]);
  }

  const size_t n = 10; 
  mpfr_prec_t prec;
  mpfr_t *x;

  //fprintf(stdout, "Precision (digits): ");
  //fscanf(stdin, "%d",&numberOfDigits);
  prec = digits2bits(numberOfDigits+1);

  sprintf(str,"%d",numberOfDigits);
  strcpy(fmt, "x(%d) = %.");
  strcat(fmt, str);
  strcat(fmt, "Re\n");

  mpfr_printf("For %d digits we need %d bytes\n",
      numberOfDigits, prec);
  fprintf(stdout,"Output string format: %s\n",fmt);
  
  x = allocate_mpfr_1D_vector(n, numberOfDigits+1);

  for (size_t i=0; i < n; i++) {
    inex = mpfr_set_ui(x[i], i, MPFR_RNDN);
    assert(inex == 0);
    mpfr_printf(fmt,i,x[i]);
  }

  free_mpfr_1D_vector(x, n);
  mpfr_free_cache();

  /* Now, let's test some operations */
  mpfr_t r, s, t;
  
  mpfr_inits2(prec, r, s, t, (mpfr_ptr) 0);

  mpfr_set_ui(r, 0, MPFR_RNDN);
  mpfr_set_str(s, "1.1", 10, MPFR_RNDN);
  mpfr_set_d(t, 5.0, MPFR_RNDN);

  mpfr_add(r, s, t, MPFR_RNDN);

  strcpy(fmt, "\ns = %.");
  strcat(fmt, str);
  strcat(fmt, "Re\n");

  mpfr_printf(fmt, s);

  strcpy(fmt, "t = %.");
  strcat(fmt, str);
  strcat(fmt, "Re\n");

  mpfr_printf(fmt,t);

  strcpy(fmt, "s+t = %.");
  strcat(fmt, str);
  strcat(fmt, "Re\n");

  mpfr_printf(fmt, r);

  mpfr_clears(r, s, t, (mpfr_ptr) 0);

  mpfr_free_cache();

  return 0;
}
