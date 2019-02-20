#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int l1 = 0;
    int l2 = 0;

    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }

    ListNode *temp = headA;
    while (temp != nullptr) {
      l1++;
      temp = temp->next;
    }

    temp = headB;
    while (temp != nullptr) {
      l2++;
      temp = temp->next;
    }

    ListNode *longer, *shorter;
    if (l1 >= l2) {
      longer = headA;
      shorter = headB;
    }
    else {
      longer = headB;
      shorter = headA;
    }

    int delta = abs(l2 - l1);

    for (int i = 0; i < delta; i++) {
      longer = longer->next;
    }

    while (longer != nullptr) {
      if (longer == shorter) {
        return longer;
      }
      longer = longer->next;
      shorter = shorter->next;
    }

    return nullptr;

  }
};

int main(void) {
  Solution sol;
  ListNode *l1 = new ListNode(4);
  l1->next = new ListNode(1);
  l1 ->next->next = new ListNode(8);
  l1 ->next->next->next = new ListNode(4);
  l1 ->next->next->next->next = new ListNode(5);
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(0);
  l2->next->next = new ListNode(1);
  l2->next->next->next = l1->next->next;
  cout << sol.getIntersectionNode(l1, l2)->val << endl;

  l1 = new ListNode(0);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(1);
  l1->next->next->next = new ListNode(2);
  l1->next->next->next = new ListNode(4);
  l2 = l1->next->next;
  cout << sol.getIntersectionNode(l1, l2)->val << endl;
  
  l2 = new ListNode(3);
  l2->next = new ListNode(4);
  cout << (sol.getIntersectionNode(l1, l2) == nullptr) << endl;



}
