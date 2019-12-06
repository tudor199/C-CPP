#include "header.h"

int main(int argc, char const *argv[]) {
  FILE *fin  = fopen("data.in", "r"),
       *fout = fopen("data.in", "w");

  printf("%s\n", "Hello world!");

  // code

  fclose(fin);
  fclose(fout);
  return 0;
}
