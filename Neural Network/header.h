#ifndef ___NN_H
#define ___NN_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


double randRange(double, double);
double square(double);
double sigmoid(double);
double sigmoid_derivate(double);


class nn {
private:
  int *nlay, noLayers,
      *nbyas, nc;
  double ***w, **lay, **bias,
          *cerr, **cw;
  double lr = 0.02;
  void initWieghts();

public:

  nn(int, int[]);
  ~nn();
  void setLearningRate(double lr);
  double train(double**, double**, int, double);
  double *  feedforward(double*);
  double backpropagation();
};

#endif
