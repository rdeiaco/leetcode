#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
      return head;
    }

    ListNode *rev_head = head;
    ListNode *interior_rev_head = head;
    ListNode *prev_tail = NULL;

    while (interior_rev_head != NULL) {
      // Check to see if there are k nodes
      // left to form a k-group.
      ListNode *t1 = interior_rev_head;
      int rev_count = 0;
      while (t1 != NULL && rev_count < k) {
        t1 = t1->next;
        rev_count++;
      }
      if (rev_count < k) {
        return rev_head;
      }

      rev_count = 0;
      ListNode *t2 = t1;
      t1 = interior_rev_head;

      // Reverse this k-group, starting at
      // interior_rev_head.
      while (rev_count < k) {
        ListNode *t3 = t1->next;
        t1->next = t2;
        t2 = t1;
        t1 = t3;
        rev_count++;
      }

      if (rev_head == head) {
        rev_head = t2;
      }
      if (prev_tail != NULL) {
        prev_tail->next = t2;
      }
      // Adjust the previous k-group's tail to the 
      // new head of this reversed k-group.
      prev_tail = interior_rev_head;
      interior_rev_head = t1;

    }

    return rev_head;
  }
};

int main(void) {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *rev_head = sol.reverseKGroup(head, 2);
  while (rev_head != NULL) {
    cout << rev_head->val << " ";
    rev_head = rev_head->next;
  }
  cout << endl;

}
