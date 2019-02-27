#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }
    return divConquerHelper(matrix, target, 0, matrix.size(), 0, matrix[0].size());

  }

  bool divConquerHelper(vector<vector<int>> &matrix, int target, int i_start, int i_end,
    int j_start, int j_end) {
    if (i_start >= i_end || j_start >= j_end) {
      return false;
    }

    int i_mid = i_start + (i_end - i_start) / 2;
    int j_mid = j_start + (j_end - j_start) / 2;

    if (matrix[i_mid][j_mid] == target) {
      return true;
    }
    if (matrix[i_mid][j_mid] > target) {
      return divConquerHelper(matrix, target, i_start, i_mid, j_start, j_mid) ||
        divConquerHelper(matrix, target, i_mid, i_end, j_start, j_mid) ||
        divConquerHelper(matrix, target, i_start, i_mid, j_mid, j_end);
    }
    else {
      return divConquerHelper(matrix, target, i_mid + 1, i_end, j_mid + 1, j_end) ||
        divConquerHelper(matrix, target, i_mid + 1, i_end, j_start, j_mid + 1) ||
        divConquerHelper(matrix, target, i_start, i_mid + 1, j_mid + 1, j_end);
    }

  }
};

int main(void) {
  Solution sol;
  vector<vector<int>> matrix;
  vector<int> row = {1, 4, 7, 11, 15};
  matrix.push_back(row); 
  row = {2, 5, 8, 12, 19};
  matrix.push_back(row); 
  row = {3, 6, 9, 16, 22};
  matrix.push_back(row); 
  row = {10, 13, 14, 17, 24};
  matrix.push_back(row); 
  row = {18, 21, 23, 26, 30};
  matrix.push_back(row); 
  cout << sol.searchMatrix(matrix, 5) << 1 << endl;
  cout << sol.searchMatrix(matrix, 0) << 0 << endl;
  cout << sol.searchMatrix(matrix, 17) << 1 << endl;
  cout << sol.searchMatrix(matrix, 20) << 0 << endl;
  cout << sol.searchMatrix(matrix, 30) << 1 << endl;
  cout << sol.searchMatrix(matrix, 23) << 1 << endl;
  cout << sol.searchMatrix(matrix, 7) << 1 << endl;
  cout << sol.searchMatrix(matrix, 1) << 1 << endl;
  cout << sol.searchMatrix(matrix, 45) << 0 << endl;
}
