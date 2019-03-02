#include "header.h"

nn::nn(int __noLayers, int nnDesc[]) {
  this->nc       = 0;
  this->noLayers = __noLayers;
  this->nlay     = new int[this->noLayers];
  this->lay      = new double *[this->noLayers];

  // cout << this->noLayers << " --- ";

  for (size_t i = 0; i < this->noLayers; i++) {
    this->nlay[i] = nnDesc[i];
    this->lay[i]  = new double[nnDesc[i]];

    if (this->nc < this->nlay[i]) {
      this->nc = this->nlay[i];
    }

    // cout << this->nlay[i] << " ";
  }

  // cout << "\n";
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
  // cout << "nn::initWieghts\n";

  srand(time(NULL));
  this->w = new double **[this->noLayers - 1];

  for (size_t k = 0; k < this->noLayers - 1; k++) {
    this->w[k] = new double *[this->nlay[k]];

    // cout << "w[" << k << "]\n";

    for (size_t i = 0; i < this->nlay[k]; i++) {
      this->w[k][i] = new double[this->nlay[k + 1]];

      for (size_t j = 0; j < this->nlay[k + 1]; j++) {
        w[k][i][j] = randRange(-1, 1);

        // cout << w[k][i][j] << " ";
      }

      // cout << "\n";
    }

    // cout << "----------------------\n";
  }

  // cout << "\n+++++++++++++++++++++++++++++++++++\n\n";


  this->bias = new double *[this->noLayers - 1];

  for (size_t k = 0; k < this->noLayers - 1; k++) {
    this->bias[k] = new double[this->nlay[k + 1]];

    // cout << "b[" << k << "]\n";

    for (size_t i = 0; i < this->nlay[k + 1]; i++) {
      this->bias[k][i] = randRange(-1, 1);

      // cout << bias[k][i] << " ";
    }

    // cout << "\n----------------------\n";
  }
}

void nn::setLearningRate(double lr) {
  this->lr = lr;
}

double * nn::feedforward(double *trainArr) {
  // // cout << "nn::feedasdforward\n";

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

double nn::backpropagation() {
  // cout << "nn::backpropagation\n";
  double *temp = new double[this->nc],
         *nle  = new double[this->nc],
         *aux;

  for (size_t k = this->noLayers - 2; k + 1 > 0; k--) {
    // calc error for layer k
    for (size_t j = 0; j < this->nlay[k + 1]; j++) {
      temp[j] = this->cerr[j];
      double wsum = 0;

      for (size_t i = 0; i < this->nlay[k]; i++) {
        wsum += this->w[k][i][j];
      }
      temp[j] /= wsum;
    }

    for (size_t i = 0; i < this->nlay[k]; i++) {
      nle[i] = 0;

      for (size_t j = 0; j < this->nlay[k + 1]; j++) {
        nle[i] += temp[j] * this->w[k][i][j];
      }

      // cout << nle[i] << " ";
    }

    // cout << "\n";

    // adjust weightsfor layer k
    for (size_t i = 0; i < this->nlay[k + 1]; i++) {
      temp[i] = this->lr * this->cerr[i] * this->lay[k + 1][i] *
                (1 - this->lay[k + 1][i]);
      this->bias[k][i] += temp[i];
    }

    // cout<<"w[" << k << "]\n";
    for (size_t i = 0; i < this->nlay[k]; i++) {
      for (size_t j = 0; j < this->nlay[k + 1]; j++) {
        this->w[k][i][j] += this->lay[k][i] * temp[j];

        // cout << w[k][i][j] << " ";
      }

      // cout << "\n";
    }

    // cout << "----------------------\n";


    aux        = nle;
    nle        = this->cerr;
    this->cerr = aux;
  }
  delete nle;
  delete temp;
  return 0;
}

double nn::train(double **trainInp, double **trainOut, int ntrain,
                 double stopErr) {
  // cout << "nn::train\n";

  this->cerr = new double[this->nc];
  this->cw   = new double *[this->nc];

  for (size_t i = 0; i < this->nc; i++) {
    this->cw[i] = new double[this->nc];
  }

  while (true) {
    double maxErr = stopErr;

    for (size_t i = 0; i < ntrain; i++) {
      double *output = this->feedforward(trainInp[i]);
      double  curErr = 0;

      for (size_t j = 0; j < this->nlay[this->noLayers - 1]; j++) {
        this->cerr[j] = trainOut[i][j] - output[j];

        if (fabs(this->cerr[j]) > curErr) {
          curErr = fabs(this->cerr[j]);
        }
      }

      // cout << output[0] << "        err: " << curErr << "\n";

      if (curErr > stopErr) {
        this->backpropagation();
      }

      if (curErr > maxErr) {
        maxErr = curErr;
      }
    }
    cout << maxErr << "\n";

    if (maxErr <= stopErr) {
      break;
    }
  }


  for (size_t i = 0; i < this->nc; i++) {
    delete this->cw[i];
  }
  delete this->cerr;
  delete this->cw;

  return 0;
}
