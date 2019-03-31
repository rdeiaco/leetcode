#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }

    vector<int> prev_row(matrix[0].size());
    vector<int> next_row(matrix[0].size());
    int max_square_length = 0;

    for (int i = 0; i < matrix[0].size(); i++) {
      if (matrix[0][i] == '1') {
        prev_row[i] = 1; 
        max_square_length = 1;
      }
      else {
        prev_row[i] = 0;
      }
    }


    for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == '1') {
        next_row[0] = 1;
        max_square_length = max(max_square_length, 1);
      }
      else {
        next_row[0] = 0;
      }
      for (int j = 1; j < matrix[i].size(); j++) {
        if (matrix[i][j] == '0') {
          next_row[j] = 0;
        }
        else {
          int new_size = min(prev_row[j], prev_row[j - 1]);
          new_size = min(new_size, next_row[j - 1]);
          next_row[j] = new_size + 1;
          max_square_length = max(max_square_length, new_size + 1);
        }
      }

      prev_row = move(next_row);
      next_row.clear();
      next_row = vector<int>(prev_row.size());
    }

    return max_square_length * max_square_length;

  }
};

int main(void) {
  Solution sol;
  
  vector<vector<char>> matrix;
  vector<char> row = {'1', '1', '1', '1', '1', '1', '1', '1'};
  matrix.push_back(row);
  row = {'1', '1', '1', '1', '1', '1', '1', '0'};
  matrix.push_back(row);
  row = {'1', '1', '1', '1', '1', '1', '1', '0'};
  matrix.push_back(row);
  row = {'1', '1', '1', '1', '1', '0', '0', '0'};
  matrix.push_back(row);
  row = {'0', '1', '1', '1', '1', '0', '0', '0'};
  matrix.push_back(row);

  cout << sol.maximalSquare(matrix) << endl;

}


