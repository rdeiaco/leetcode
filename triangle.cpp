#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.size() == 0) {
      return 0;
    }
    if (triangle.size() == 1) {
      return triangle[0][0];
    }

    int best_cost = INT_MAX;
    for (int i = 1; i < triangle.size(); i++) {
      for (int j = 0; j < triangle[i].size(); j++) {
        int cost = INT_MAX;
        if (j > 0) {
          cost = min(cost, triangle[i - 1][j - 1] + triangle[i][j]);
        }
        if (j < triangle[i - 1].size()) {
          cost = min(cost, triangle[i - 1][j] + triangle[i][j]);
        }
        triangle[i][j] = cost;

        if (i == triangle.size() - 1 && cost < best_cost) {
          best_cost = cost; 
        }
      }
    }

    return best_cost;

  }
};

int main(void) {
  Solution sol;
  vector<vector<int>> triangle;
  vector<int> row = {2};
  triangle.push_back(row);
  row = {3, 4};
  triangle.push_back(row);
  row = {6, 5, 7};
  triangle.push_back(row);
  row = {4, 1, 8, 3};
  triangle.push_back(row);
  cout << sol.minimumTotal(triangle) << endl;

  triangle.clear();
  cout << sol.minimumTotal(triangle) << endl;

  row = {45};
  triangle.push_back(row);
  cout << sol.minimumTotal(triangle) << endl;


}
