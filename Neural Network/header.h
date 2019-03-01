#ifndef ___NN_H
#define ___NN_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


double randRange(double, double);
double sigmoid(double);


class nn {
private:
  int *nlay, noLayers,
      *nbyas;
  double ***w, **lay, **bias;
  double lr = 0.1;
  void initWieghts();

public:

  nn(int, int[]);
  ~nn();
  double train(double**, double**, int, double);
  double *  feedforward(double*);
  double backpropagation(double);
};

#endif
