/* Write code for a function with the following prototype: */
/* /\* */
/* * Mask with least signficant n bits set to 1 */
/* * Examples: n = 6 --> 0x2F, n = 17 --> 0x1FFFF */
/* * Assume 1 <= n <= w */
/* *\/ */
/* int lower_one_mask(int n); */
/* Your function should follow the bit-level integer coding rules (page 120). Be */
/* careful of the case n = w. */

#include <assert.h>
#include <stdio.h>

int lower_one_mask(int n) {
  //printf("n: %d, int: %d\n", n, sizeof(int) * 8);
  assert(1 <= n && n <= sizeof(int) * 8);

  // In case of n = w, use n - 1 instead of n as number of bits to shift
  return (2 << (n - 1)) - 1;
}

static void test() {
  //assert(lower_one_mask(0) == 0x0);
  assert(lower_one_mask(1) == 0x1);
  assert(lower_one_mask(2) == 0x3);
  assert(lower_one_mask(4) == 0xf);
  assert(lower_one_mask(6) == 0x3f);
  assert(lower_one_mask(17) == 0x1ffff);
  assert(lower_one_mask(32) == 0xffffffff);
}

int main() {
  test();

  return 0;
}
