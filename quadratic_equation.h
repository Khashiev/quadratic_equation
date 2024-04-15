#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>

typedef struct {
  double x1;
  double x2;
} Roots;

Roots solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H