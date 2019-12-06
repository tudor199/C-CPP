#include "func.h"

int main(int argc, char const *argv[]) {
    FILE *fin;
	if ((fin = fopen("data.in", "r")) == NULL) {
		return -1;
	}

	double no_s[NMAX];
	int no_n = 0;
	char op;
	double no;
	while(op = fgetc(fin)) {
		if (op == ' ') {
			continue;
        }
		if (op == '\n') {
			break;
		}
		if (is_digit(op)) {
			fseek(fin, -1, SEEK_CUR);
				fscanf(fin, "%lf", &no);
                no_s[no_n++] = no;
				continue;
		}
        double  no2 = no_s[--no_n],
                no1 = no_s[--no_n];
        switch (op) {
        case '+':
            no_s[no_n++] = no1 + no2;
            break;
        case '-':
            no_s[no_n++] = no1 - no2;
            break;
        case '*':
            no_s[no_n++] = no1 * no2;
            break;
        case '/':
            no_s[no_n++] = no1 / no2;
            break;
        }
	}
    printf("%lf\n", no_s[0]);
	fclose(fin);
	return 0;
}
