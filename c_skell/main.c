#include "func.h"

int main(int argc, char const *argv[]) {
    FILE *fin, *fout;
	if ((fin = fopen("data.in", "r")) == NULL) {
		return -1;
	}
	if ((fout = fopen("data.in", "w")) == NULL) {
    	fclose(fin);
		return -1;
    }

    //code

	fclose(fin);
	fclose(fout);
	return 0;
}
