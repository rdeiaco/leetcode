class Solution {
public:
  int findComplement(int num) {
    // Find the number of leading zeroes.
    int i;
    int leading_zeroes = 0;
    int result;
    unsigned int mask;
    for (i = 31; i > 0; i--) {
      if (((num >> i) & 0x1) | 0) {
        break;
      }
      else {
        leading_zeroes++;
      }
    }

    // Take the complement.
    result = ~num;

    // Mask the result.
    mask = 0xFFFFFFFF >> leading_zeroes;
    result &= mask;
    return result;
  }
};
