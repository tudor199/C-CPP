#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define INF 1000000

using namespace std;

double f1(double x, double y) {
	return -1.0* x * x - 1.0 * y * y + 4.0 * x + 6.0 * y;
}

int check_domain1(double x, double y) {
	if (x < 0) {
		return 0;
	}
	if (y < 0) {
		return 0;
	}
	return x + y <= 64;
}

double f2(double x, double y) {
	return 2.0 * x * x + 3.0 * y * y - 4.0 * x - 5;
}
;
int check_domain2(double x, double y) {
	return x * x + y * y <= 16;
}






double rand_sign() {
	return ((rand() % 2) ? -1.0 : 1.0);
}

void fminmax(double (*f)(double, double), int (*check)(double, double)) {
	srand(time(NULL));
	double min = INF, max = -INF, xmin, xmax, ymin, ymax;
	while (1) {
		double x = rand_sign() *  rand() / rand();
		double y = rand_sign() *  rand() / rand();
		if(check(x, y)) {
			double res = (*f)(x, y);
			if (res < min) {
				xmin = x;
				ymin = y;
				min = res;
			}
			if (res > max) {
				xmax = x;
				ymax = y;
				max = res;
			}
			cout<<"------------------------------------------\n";
      cout<<"MIN:   "<<xmin<<"   "<<ymin<<"   "<<min<<"\n";
      cout<<"MIN:   "<<xmax<<"   "<<ymax<<"   "<<max<<"\n";
      cout<<"MIN:   "<<x<<"   "<<y<<"   "<<(*f)(x, y)<<"\n";
      cout<<"------------------------------------------\n";
		}
	}
}

int main() {
	fminmax(f1, check_domain1);
    return 0;
}
