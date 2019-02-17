#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
      int mincostTickets(vector<int> &days, vector<int> &costs) {
        int cost_table[365] = {0};
        return recurse_helper(days, costs, 0, cost_table); 
      }

      int recurse_helper(vector<int> &days, vector<int> &costs, int index, int cost_table[]) {

        if (index == days.size()) {
          return 0;
        }

        if (cost_table[days[index]] != 0) {
          return cost_table[days[index]];
        }

        int one_index, seven_index, thirty_index;
        bool one_found, seven_found, thirty_found;
        one_index = seven_index = thirty_index = days.size();
        one_found = seven_found = thirty_found = false;
        

        for (size_t i = index + 1; i < days.size(); i++) {
          if (!one_found && days[i] > days[index]) {
            one_index = i;  
            one_found = true;
          } 
          if (!seven_found && days[i] > days[index] + 6) {
            seven_index = i; 
            seven_found = true;
          }
          if (!thirty_found && days[i] > days[index] + 29) {
            thirty_index = i; 
            thirty_found = true;
          }
        }

        int one_cost = costs[0] + recurse_helper(days, costs, one_index, cost_table);
        int seven_cost = costs[1] + recurse_helper(days, costs, seven_index, cost_table);
        int thirty_cost = costs[2] + recurse_helper(days, costs, thirty_index, cost_table);

        cost_table[days[index]] = min(one_cost, min(seven_cost, thirty_cost));
        return cost_table[days[index]];

      }
};

int main(void) {
  Solution sol;
  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {2, 7, 15};
  cout << sol.mincostTickets(days, costs) << "\n";

  days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  costs = {2, 7, 15};
  cout << sol.mincostTickets(days, costs) << "\n";
}
