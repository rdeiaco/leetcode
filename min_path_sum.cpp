#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (i > 0 && j > 0) {
          grid[i][j] = min(grid[i][j] + grid[i - 1][j], grid[i][j] + grid[i][j - 1]);
        }
        else if (i > 0) {
          grid[i][j] = grid[i][j] + grid[i - 1][j];

        }
        else if (j > 0) {
          grid[i][j] = grid[i][j] + grid[i][j - 1];
        }
      }
    }

    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};

int main(void) {
  Solution sol;
  vector<vector<int>> grid;
  vector<int> row = {1, 2};
  grid.push_back(row);
  row = {5, 6};
  grid.push_back(row);
  row = {1, 1};
  grid.push_back(row);

  cout << sol.minPathSum(grid) << endl;
  
}
