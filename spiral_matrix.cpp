#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    if (matrix.size() == 0) {
      return result;
    }

    int row_start = 0;
    int row_end = matrix.size();
    int col_start = 0;
    int col_end = matrix[0].size();
    while(col_start < col_end && row_start < row_end) {
      for (int j = col_start; j < col_end; j++) {
        result.push_back(matrix[row_start][j]);  
      } 
      row_start++;
      if (row_start >= row_end) {
        break;
      }

      for (int i = row_start; i < row_end; i++) {
        result.push_back(matrix[i][col_end - 1]);
      }
      col_end--;
      if (col_start >= col_end) {
        break;
      }

      for (int j = col_end - 1; j >= col_start; j--) {
        result.push_back(matrix[row_end - 1][j]);
      }
      row_end--;
      if (row_start >= row_end) {
        break;
      }

      for (int i = row_end - 1; i >= row_start; i--) {
        result.push_back(matrix[i][col_start]);
      }
      col_start++;
    }

    return result; 

  }
};

int main(void) {
  Solution sol;
  vector<vector<int>> matrix;
  vector<int> row = {1, 2, 3, 4};
  matrix.push_back(row);
  row = {5, 6, 7, 8};
  matrix.push_back(row);
  row = {9, 10, 11, 12};
  matrix.push_back(row);
  row = {13, 14, 15, 16};
  matrix.push_back(row);

  vector<int> result = sol.spiralOrder(matrix);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

}
