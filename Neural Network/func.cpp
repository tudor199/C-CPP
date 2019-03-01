#include "header.h"

double randRange(double a, double b) {
  return a + static_cast<double>(rand()) /
         (static_cast<double>(RAND_MAX / (b - a)));
}

double sigmoid(double x) {
  return 1.0 / ( 1 + exp(-x));
}
