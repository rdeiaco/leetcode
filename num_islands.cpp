#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }

    int num_islands = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '0') {
          continue;
        }
      

        num_islands++; 
        bool visited[grid.size()][grid[0].size()]; 
        for (int k = 0; k < grid.size(); k++) {
          for (int l = 0; l < grid[0].size(); l++) {
            visited[k][l] = false;
          }
        }

        queue<pair<int, int>> land_queue;
        land_queue.push(pair<int, int>(i, j));
        visited[i][j] = true;

        while (!land_queue.empty()) {
          pair<int, int> u = land_queue.front();
          land_queue.pop();

          grid[u.first][u.second] = '0';

          if (u.first + 1 < grid.size() && !visited[u.first + 1][u.second] 
            && grid[u.first + 1][u.second] == '1') {
            land_queue.push(pair<int, int>(u.first + 1, u.second));
            visited[u.first + 1][u.second] = true;
          }

          if (u.second + 1 < grid[0].size() && !visited[u.first][u.second + 1] 
            && grid[u.first][u.second + 1] == '1') {
            land_queue.push(pair<int, int>(u.first, u.second + 1));
            visited[u.first][u.second + 1] = true;
          }

          if (u.first - 1 >= 0 && !visited[u.first - 1][u.second] 
            && grid[u.first - 1][u.second] == '1') {
            land_queue.push(pair<int, int>(u.first - 1, u.second));
            visited[u.first - 1][u.second] = true;
          }

          if (u.second - 1 >= 0 && !visited[u.first][u.second - 1] 
            && grid[u.first][u.second - 1] == '1') {
            land_queue.push(pair<int, int>(u.first, u.second - 1));
            visited[u.first][u.second - 1] = true;
          }

        }
      }
    }

    return num_islands;

  }
};

int main(void) {
  Solution sol;
  vector<vector<char>> grid;

  vector<char> row = {'1', '1', '1', '1', '0'};
  grid.push_back(row);
  row = {'1', '1', '0', '1', '0'};
  grid.push_back(row);
  row = {'1', '1', '0', '0', '0'};
  grid.push_back(row);
  row = {'0', '0', '0', '0', '0'};
  grid.push_back(row);
  cout << sol.numIslands(grid) << endl;

  grid.clear();
  row = {'1', '1', '0', '0', '0'};
  grid.push_back(row);
  row = {'1', '1', '0', '0', '0'};
  grid.push_back(row);
  row = {'0', '0', '1', '0', '0'};
  grid.push_back(row);
  row = {'0', '0', '0', '1', '1'};
  grid.push_back(row);
  cout << sol.numIslands(grid) << endl;

  grid.clear();
  row = {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
  grid.push_back(row);
  cout << sol.numIslands(grid) << endl;

  grid.clear();
  grid = {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
          {'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
          {'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
          {'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
          {'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
          {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
  cout << sol.numIslands(grid) << endl;
}
