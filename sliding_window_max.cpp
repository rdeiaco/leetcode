#include <vector>
#include <iostream>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> number_queue;
    vector<int> sliding_window;
  
    int curr_max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {

      if (number_queue.size() == k) {
        int leaving = number_queue.front();
        number_queue.pop_front();

        if (leaving == curr_max) {
          curr_max = INT_MIN;
          int max_index = -1;
          for (int j = 0; j < number_queue.size(); j++) {
            if (number_queue[j] > curr_max) {
              curr_max = number_queue[j];
              max_index = j;
            }
          }

          for (int j = 0; j < max_index; j++) {
            number_queue.pop_front();
          }
        }
      }

      if (nums[i] > curr_max) {
        curr_max = nums[i];
      }

      number_queue.push_back(nums[i]);
      if (i >= k-1) {
        sliding_window.push_back(curr_max);
      }
    }

  return sliding_window;

  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {1, 3, -1, -1, -1, 3, 6, 7};
  vector<int> result = sol.maxSlidingWindow(nums, 3);

  for (int i : result) {
    cout << i  << " ";
  }
  cout << endl;
}
