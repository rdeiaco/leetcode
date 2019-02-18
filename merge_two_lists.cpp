#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *merged = nullptr;
      ListNode *temp = merged;
      int val_to_add;

      while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) { 
          val_to_add = l1->val;
          l1 = l1->next;
        }
        else {
          val_to_add = l2->val;
          l2 = l2->next;
        }

        if (merged == nullptr) {
          merged = new ListNode(val_to_add);
          temp = merged;
        }
        else {
          temp->next = new ListNode(val_to_add);
          temp = temp->next;
        }
      }

      while (l1 != nullptr) {
        val_to_add = l1->val;
        l1 = l1->next;
        if (merged == nullptr) {
          merged = new ListNode(val_to_add);
          temp = merged;
        }
        else {
          temp->next = new ListNode(val_to_add);
          temp = temp->next;
        }
      }

      while (l2 != nullptr) {
        val_to_add = l2->val;
        l2 = l2->next;
        if (merged == nullptr) {
          merged = new ListNode(val_to_add);
          temp = merged;
        }
        else {
          temp->next = new ListNode(val_to_add);
          temp = temp->next;
        }
      }

      return merged;
    }
};

int main(void) {
  Solution sol;
  ListNode *merged = sol.mergeTwoLists(nullptr, nullptr);
  cout << (merged == nullptr) << "\n";

  ListNode *l1, *l2, *temp;
  l1 = new ListNode(1);
  l1->next = new ListNode(1);
  temp = l1->next;
  temp->next = new ListNode(4);

  merged = sol.mergeTwoLists(l1, nullptr);
  temp = merged;
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";

  merged = sol.mergeTwoLists(nullptr, l1);
  temp = merged;
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";
  
  l2 = new ListNode(2);
  l2->next = new ListNode(3);
  merged = sol.mergeTwoLists(l1, l2);
  temp = merged;
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "\n";

}
