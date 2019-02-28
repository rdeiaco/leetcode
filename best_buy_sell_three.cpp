#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }
    // max_prof is the maximum profit possible buying at 
    // time i with one transaction.
    int max_prof[prices.size()] = {0};
    // max_rem_rev is the maximum revenue possible if you
    // sell at index i and buy/sell at any index >= i + 1.
    int max_rem_prof[prices.size()] = {0};
    int max_rem_rev[prices.size()] = {0};


    // First, compute the maximum revenue possible from buying at
    // index i.
    max_prof[prices.size() - 1] = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
      max_prof[i] = max(max_prof[i + 1], prices[i + 1]);
    }
    // Then, compute the maximum profit possible by subtracting the
    // cost of buying at i.
    for (int i = 0; i < prices.size(); i++) {
      max_prof[i] -= prices[i];
    }

    
    // First, compute the maximum remaining profit possible if
    // you could buy at any index >= i.
    max_rem_prof[prices.size() - 1] = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
      max_rem_prof[i] = max(max_rem_prof[i + 1], max_prof[i]);
    }

    // Then compute the maximum remaining revenue possible if you sold at any
    // index j, then bought at any index k > j and sold at any index l > k.
    max_rem_rev[0] = 0;
    max_rem_rev[prices.size() - 1] = 0;
    max_rem_rev[prices.size() - 2] = 0;
    for (int i = prices.size() - 3; i >= 1; i--) {
      max_rem_rev[i] = max(prices[i] + max_rem_prof[i + 1], max_rem_rev[i + 1]);
    }

    int best_profit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      best_profit = max(max_prof[i], max(max_rem_rev[i + 1] - prices[i], best_profit));
    }

    return best_profit;

  }
};


int main(void) {
  Solution sol;
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  cout << sol.maxProfit(prices) << endl;
  prices = {1, 2, 3, 4, 5};
  cout << sol.maxProfit(prices) << endl;
  prices = {7, 6, 4, 3, 1};
  cout << sol.maxProfit(prices) << endl;
}
