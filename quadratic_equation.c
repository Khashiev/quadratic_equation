#include "quadratic_equation.h"

Roots solve_equation(double a, double b, double c) {
  Roots roots = {0};
  double D = b * b - 4 * a * c;

  if (D < 0) {
    roots.x1 = roots.x2 = NAN;
  } else if (D == 0) {
    roots.x1 = roots.x2 = -b / (2 * a);
  } else {
    roots.x1 = (-b + sqrt(D)) / (2 * a);
    roots.x2 = (-b - sqrt(D)) / (2 * a);
  }

  return roots;
}
