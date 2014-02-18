/* Write code to implement the following function: */
/* /\* Return 1 when x contains an odd number of 1s; 0 otherwise. */
/* Assume w=32. *\/ */
/* int odd_ones(unsigned x); */
/* Your function should follow the bit-level integer coding rules (page 120), except */
/* that you may assume that data type int has w = 32 bits. */
/* Your code should contain a total of at most 12 arithmetic, bit-wise, and logical */
/* operations. */

#include <assert.h>

int odd_ones(unsigned x) {
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;

  //return x; // this one is wrong, should know the reason
  return x & 1;
}

static void test() {
  int x0 = 0x0;
  int x1 = 0x1;
  int x2 = 0x11;
  int x3 = 0x111;
  int x4 = 0x1111;
  int x5 = 0x11111;
  int x6 = 0x111111;
  int x7 = 0x1111111;
  int x8 = 0x11111111;

  assert(odd_ones(x0) == 0);
  assert(odd_ones(x1) == 1);
  assert(odd_ones(x2) == 0);
  assert(odd_ones(x3) == 1);
  assert(odd_ones(x4) == 0);
  assert(odd_ones(x5) == 1);
  assert(odd_ones(x6) == 0);
  assert(odd_ones(x7) == 1);
  assert(odd_ones(x8) == 0);
}

int main() {
  test();

  return 0;
}
