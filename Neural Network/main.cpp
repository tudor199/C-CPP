#include "header.h"

int main(int argc, char const *argv[]) {
  ifstream fin("data.in");
  ifstream fout("data.out");

  int *nnDesc, layers;

  fin >> layers;
  nnDesc = new int[layers];

  for (size_t i = 0; i < layers; i++) {
    fin >> nnDesc[i];
  }

  int ntrain;
  double **trainInp, **trainOut, err;
  fin >> ntrain >> err;
  trainInp = new double *[ntrain];
  trainOut = new double *[ntrain];

  for (size_t i = 0; i < ntrain; i++) {
    trainInp[i] = new double[nnDesc[0]];
    trainOut[i] = new double[nnDesc[layers - 1]];

    for (size_t j = 0; j < nnDesc[0]; j++) {
      fin >> trainInp[i][j];
    }

    for (size_t j = 0; j < nnDesc[layers - 1]; j++) {
      fin >> trainOut[i][j];
    }
  }


  nn *brain = new nn(layers, nnDesc);
  brain->train(trainInp, trainOut, ntrain, err);


  for (size_t i = 0; i < layers; i++) {
    delete trainInp[i];
    delete trainOut[i];
  }
  delete brain;
  delete nnDesc;
  delete trainInp;
  delete trainOut;

  fout.close();
  fin.close();
  return 0;
}
