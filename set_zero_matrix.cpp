#include <vector>
#include <set>

class Solution {
  public:
  void setZeroes(vector<vector<int>> &matrix) {
    std::set<int> rows, cols;
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    int i, j;

    for (i = 0; i < num_rows; i++) {
      for (j = 0; j < num_cols; j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }
    for (std::set<int>::iterator ir = rows.begin(); ir != rows.end(); ir++) {
      for (j = 0; j < num_cols; j++) {
        matrix[*ir][j] = 0;
      }
    }
    for (std::set<int>::iterator ic = cols.begin(); ic != cols.end(); ic++) {
      for (i = 0; i < num_rows; i++) {
        matrix[i][*ic] = 0;
      }
    }
  }
};
