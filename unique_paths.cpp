#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }

    int count = 0;
    int lut[100][100];
    memset(lut, -1, sizeof(lut[0][0]) * 100 * 100);
    count = dfsHelper(0, 0, n, m, lut);

    return count;
  }

  int dfsHelper(int row, int col, int num_rows, int num_cols, int lut[100][100]) {
    if (row == num_rows - 1 && col == num_cols - 1) {
      return 1;
    }
    if (lut[row][col] != -1) {
      return lut[row][col];
    }
    else{
      int temp_count = 0;
      if (row < num_rows - 1) {
        temp_count += dfsHelper(row + 1, col, num_rows, num_cols, lut);
      }
      if (col < num_cols - 1) {
        temp_count += dfsHelper(row, col + 1, num_rows, num_cols, lut);
      }

      lut[row][col] = temp_count;
      return temp_count;
    }
  }
};

int main(void) {
  Solution sol;
  cout << sol.uniquePaths(3, 2) << endl;
  cout << sol.uniquePaths(7, 3) << endl;
  cout << sol.uniquePaths(30, 30) << endl;
}
