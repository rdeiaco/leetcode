#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *merged = nullptr;
    ListNode *temp;
    bool remaining_flag = true; 

    while (remaining_flag) {
      remaining_flag = false;
      int min_val = INT_MAX;
      int min_index = 0;

      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] == nullptr) {
          continue;
        }

        if (lists[i]->val <= min_val) {
          min_val = lists[i]->val;
          min_index = i; 
          remaining_flag = true;
        }

      }

      if (remaining_flag) {
        if (merged == nullptr) {
          merged = new ListNode(min_val);
          temp = merged;
        }
        else {
          temp->next = new ListNode(min_val);
          temp = temp->next;
        }

        lists[min_index] = lists[min_index]->next;
      }
    }

    return merged;
  }
};

int main(void) {
  Solution sol;
  vector<ListNode*> v1;
  ListNode *l1 = nullptr;
  v1.push_back(l1);
  cout << (sol.mergeKLists(v1) == nullptr) << "\n";

  v1.clear();
  l1 = new ListNode(1);
  l1->next = new ListNode(3);
  l1->next->next = new ListNode(7);

  ListNode *l2, *l3;

  l2 = new ListNode(2);
  l2->next = new ListNode(2);

  l3 = new ListNode(4);
  l3->next = new ListNode(5);
  l3->next->next = new ListNode(8);
  l3->next->next->next = new ListNode(24);

  v1 = {l1, l2, l3};
  ListNode *merged = sol.mergeKLists(v1);
  while (merged != nullptr) {
    cout << merged->val << " ";
    merged = merged->next;
  }
  cout << "\n";

}
