#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) {
       pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] > pq.top()) {
        pq.pop();
        pq.push(nums[i]);
      }
    }

    return pq.top();

  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  cout << sol.findKthLargest(nums, 2) << endl;
  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  cout << sol.findKthLargest(nums, 4) << endl;

}
