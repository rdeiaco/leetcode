#include <vector>
#include <iostream>
#include <utility>

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }

    vector<int> prev_row[matrix[0].size()];
    vector<int> prev(4) = {0};
    int biggest_size = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '1') {
          int left_height = 0;
          int left_width = 0;
          int top_height = 0;
          int top_width = 0;

          // See how much we can extend the above rectangle.
          if (i > 0) {
            top_height = prev_row[j];
            top_width = prev_row[j].second;
          } 
          if (j > 0) {
            left_height = prev.first;
            left_width = prev.second;
          }
          if (left_width >= top_width - 1) {

          }
            
        } 
      }
    }
    
  }
};


