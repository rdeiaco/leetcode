#include <vector>
#include <iostream>

class Solution {
  public:
  bool searchMatrix(std::vector< std::vector<int> >& matrix, int target) {
    int rows, cols, i, j, step;
    int start, end;

    // Check for null cases.
    rows = matrix.size();
    if (rows == 0) {
      return false;
    }
    cols = matrix[0].size();
    if (cols == 0) {
      return false;
    }

    // Do a binary search on the rows until we find one that must contain the target.
    start = 0;
    end = rows - 1;
    i = (end - start) / 2;
    while (1) {
      if (target == matrix[i][cols-1]) {
        return true;
      }

      // Target is greater than all the values before the end of this row, continue searching.
      else if (target > matrix[i][cols-1]) {
        start = i;
        step = (end - start) / 2;
        if (step == 0) {
          step = 1;
        }
        i += step;

        // If i is now greater than the number of rows, target is not in the matrix.
        if (i >= rows) {
          return false;
        }
      }

      else if (target < matrix[i][cols-1]) {
        // Check to see if this is the zeroth row, in which case the target will be in this
        // row if it is in the matrix.
        if (i == 0) {
          break;
        }

        // Else, see if the target is greater or equal to than the end of the previous row.
        else if (target == matrix[i-1][cols-1]) {
          return true;
        }
        else if (target > matrix[i-1][cols-1]) {
          break;
        }

        // Else, continue searching.
        else {
          end = i;
          step = (end - start) / 2;
          if (step == 0) {
            step = 1;
          }
          i -= step;
        }
      }
    }

    // Do a binary search on the values in this row until we find the target.
    start = 0;
    end = cols - 1;
    j = (end - start) / 2;
    while (1) {
      if (target == matrix[i][j]) {
        return true;
      }
      else if (target > matrix[i][j]) {
        // No more values left to search.
        if (j == (cols - 1)) {
          return false;
        }
        if (target < matrix[i][j+1]) {
          return false;
        }
        // Else, continue search.
        start = j;
        step = (end - start) / 2;
        if (step == 0) {
          step = 1;
        }
        j += step;
      }
      else if (target < matrix[i][j]) {
        // No more values left to search.
        if (j == 0) {
          return false;
        }
        if (target > matrix[i][j-1]) {
          return false;
        }
        // Else, continue search.
        end = j;
        step = (end - start) / 2;
        if (step == 0) {
          step = 1;
        }
        j -= step;
      }
    }
  }
};

int main(void) {
  Solution sol;
  std::vector< std::vector<int> > matrix;
  static const int rows = 10;
  static const int cols = 12;
  int n;

  for (int i = 0; i < rows; i++) {
    std::vector<int> row;
    for (int j = 0; j < cols; j++) {
      row.push_back(1 + 2*j + 2*i*cols);
    }
    matrix.push_back(row);
  }
  while(1) {
    std::cout << "Enter a number:\n";
    std::cin >> n;
    std::cout << sol.searchMatrix(matrix, n) << '\n'; 
  }
  return 0;
}
