#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) {
      return 0;
    }
    int best_buying_price = prices[0];
    int best_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      int temp_profit = prices[i] - best_buying_price;
      if (temp_profit > best_profit) {
        best_profit = temp_profit;
      }
      best_buying_price = min(best_buying_price, prices[i]);
    }

    return best_profit;

  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  cout << sol.maxProfit(nums) << endl;
  nums = {7, 6, 4, 3, 1};
  cout << sol.maxProfit(nums) << endl;
}
