#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }

    int max_area = 0;
    vector<int> prev_row(matrix[0].size());
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == '1') {
          if (i == 0) {
            prev_row[j] = 1;
          }
          else {
            prev_row[j] += 1;
          }
        }
        else {
          prev_row[j] = 0;
        }
      }
      max_area = max(max_area, computeArea(prev_row));
    }

    return max_area;
  }

  int computeArea(vector<int> &prev_row) {
    stack<int> index_stack;

    int max_area = 0;
    for (int i = 0; i < prev_row.size(); i++) {
      if (index_stack.empty() || prev_row[i] >= prev_row[index_stack.top()]) {
        index_stack.push(i);
      }
      else { 
        while (!index_stack.empty() && prev_row[i] < prev_row[index_stack.top()]) {
          int smallest_rect_index = index_stack.top();
          index_stack.pop();
          // Left and right index (inclusive) give the range of the max width rectangle
          // of height at smallest rect_index.
          int left_index = 0;
          if (index_stack.empty()) {
            left_index = 0;
          }
          else {
            left_index = index_stack.top() + 1;
          }
          int right_index = i - 1;
          max_area = max(max_area, prev_row[smallest_rect_index] * (right_index - left_index + 1)); 
        }
        index_stack.push(i);
      }
    }

    while (!index_stack.empty()) {
      int smallest_rect_index = index_stack.top();
      index_stack.pop();
      int left_index = 0;
      if (index_stack.empty()) {
        left_index = 0;
      }
      else {
        left_index = index_stack.top() + 1;
      }
      int right_index = prev_row.size() - 1;
      max_area = max(max_area, prev_row[smallest_rect_index] * (right_index - left_index + 1)); 
    }

    return max_area;
  }
};

int main(void) {
  Solution sol;
  vector<vector<char>> matrix;
  vector<char> row = {'0', '1', '1', '0', '1'};
  matrix.push_back(row);
  row = {'1', '1', '0', '1', '0'};
  matrix.push_back(row);
  row = {'0', '1', '1', '1', '0'};
  matrix.push_back(row);
  row = {'1', '1', '1', '1', '0'};
  matrix.push_back(row);
  row = {'1', '1', '1', '1', '1'};
  matrix.push_back(row);
  row = {'0', '0', '0', '0', '0'};
  matrix.push_back(row);

  cout << sol.maximalRectangle(matrix) << endl;

}
