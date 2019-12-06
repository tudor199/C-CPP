#include "func.h"

int is_digit(char c) {
  return ('0' <= c && c <= '9');
}
int is_white_space(char c) {
  return (c == ' ' || c == '\t' || c == '\n');
}
