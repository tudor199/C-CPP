#include "header.h"

nn::nn(int __noLayers, int nnDesc[]) {
  this->noLayers = __noLayers;
  this->nlay     = new int[this->noLayers];
  this->lay      = new double *[this->noLayers];

  cout << this->noLayers << " --- ";

  for (size_t i = 0; i < this->noLayers; i++) {
    this->nlay[i] = nnDesc[i];
    this->lay[i]  = new double[nnDesc[i]];
    cout << this->nlay[i] << " ";
  }
  cout << "\n";

  this->initWieghts();
}

nn::~nn() {
  for (size_t i = 0; i < this->noLayers - 1; i++) {
    for (size_t j = 0; j < this->nlay[i]; j++) {
      delete this->w[i][j];
    }
    delete this->w[i];
    delete this->bias[i];
  }
  delete this->w;


  for (size_t i = 0; i < this->noLayers - 1; i++) {
    delete this->bias[i];
  }
  delete this->bias;


  for (size_t i = 0; i < this->noLayers; i++) {
    delete this->lay[i];
  }
  delete this->nlay;
  delete this->lay;
}

void nn::initWieghts() {
  cout << "nn::initWieghts\n";

  srand(time(NULL));
  this->w = new double **[this->noLayers - 1];

  for (size_t k = 0; k < this->noLayers - 1; k++) {
    this->w[k] = new double *[this->nlay[k]];
    cout << "w[" << k << "]\n";

    for (size_t i = 0; i < this->nlay[k]; i++) {
      this->w[k][i] = new double[this->nlay[k + 1]];

      for (size_t j = 0; j < this->nlay[k + 1]; j++) {
        w[k][i][j] = randRange(-1, 1);
        cout << w[k][i][j] << " ";
      }
      cout << "\n";
    }
    cout << "----------------------\n";
  }
  cout << "\n+++++++++++++++++++++++++++++++++++\n\n";


  this->bias = new double *[this->noLayers - 1];

  for (size_t k = 0; k < this->noLayers - 1; k++) {
    this->bias[k] = new double[this->nlay[k + 1]];
    cout << "b[" << k << "]\n";

    for (size_t i = 0; i < this->nlay[k + 1]; i++) {
      this->bias[k][i] = randRange(-1, 1);
      cout << bias[k][i] << " ";
    }
    cout << "\n----------------------\n";
  }
}

double * nn::feedforward(double *trainArr) {
  // cout << "nn::feedasdforward\n";

  for (size_t k = 0; k < this->nlay[0]; k++) {
    this->lay[0][k] = trainArr[k];
  }

  for (size_t k = 0; k < this->noLayers - 1; k++) {
    for (size_t j = 0; j < this->nlay[k + 1]; j++) {
      this->lay[k + 1][j] = this->bias[k][j];

      for (size_t i = 0; i < this->nlay[k]; i++) {
        this->lay[k + 1][j] += this->w[k][i][j] *
                               this->lay[k][i];
      }
      this->lay[k + 1][j] = sigmoid(this->lay[k + 1][j]);
    }
  }

  return this->lay[this->noLayers - 1];
}
double nn::backpropagation(double curErr) {
  return 0;
}


double nn::train(double **trainInp, double **trainOut, int ntrain,
                 double stopErr) {
  // new
  cout << "nn::train\n";
  // cout << ntrain << " " << stopErr << "\n";

while(true){
  double maxErr = stopErr;
  for (size_t i = 0; i < ntrain; i++) {
    double *output = this->feedforward(trainInp[i]);
    cout << output[0];
    double curErr = 0;
    for (size_t j = 0; j < this->nlay[this->noLayers - 1]; j++) {
      curErr += trainOut[i][j] - output[j];
    }
    curErr = fabs(curErr / this->nlay[this->noLayers - 1]);
    if (curErr > maxErr) {
      this->backpropagation(curErr);
      maxErr = curErr;
    }
    cout<<"        err: "<<curErr<<"\n";
  }
  cout << maxErr <<"\n";
  if (maxErr == stopErr) {
    break;
  }
}

  // while (true) {
  //   double curErr = this->feedforward();
  //
  //   if (curErr <= stopErr) break;
  // }


  return 0;
}
