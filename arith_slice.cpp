class Solution {
  public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int slices = 0;

    if (A.size() < 3) {
      return 0;
    }

    // Each slice has a minimum of 3 values.
    for (int i = 0; i < (A.size() - 2); i++) {
      // Get the difference between the following element and the current element..
      int diff = A[i+1] - A[i];
      for (int j = (i + 1); j < (A.size() - 1); j++) {
        if ((A[j+1] - A[j]) == diff) {
          slices++;
        }
        else {
          break;
        }
      }
    }
    return slices;
  }
};
