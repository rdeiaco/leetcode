#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *temp1, *temp2, *temp3;
      temp1 = l1;
      temp2 = l2;
      ListNode *sum = NULL;


      int carry = 0;
      while ((temp1 != NULL) && (temp2 != NULL)) {
        int temp_sum = temp1->val + temp2->val + carry;
        carry = 0;

        if (temp_sum >= 10) {
          temp_sum -= 10;
          carry = 1;
        }

        if (sum == NULL) {
          sum = new ListNode(temp_sum);
          temp3 = sum;
        }
        else {
          temp3->next = new ListNode(temp_sum);
          temp3 = temp3->next;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
      }

      while (temp1 != NULL) {
        int temp_sum = temp1->val + carry;
        carry = 0;
        if (temp_sum >= 10) {
          temp_sum -= 10;
          carry = 1;
        }
        temp3->next = new ListNode(temp_sum);
        temp3 = temp3->next;
        temp1 = temp1->next;
      }
      while (temp2 != NULL) {
        int temp_sum = temp2->val + carry;
        carry = 0;
        if (temp_sum >= 10) {
          temp_sum -= 10;
          carry = 1;
        }
        temp3->next = new ListNode(temp_sum);
        temp3 = temp3->next;
        temp2 = temp2->next;
      }

      if (carry != 0) {
        temp3->next = new ListNode(carry);
      }

      return sum;

    }
};

int main(void) {
  ListNode *t1;
  ListNode* l1 = new ListNode(2);
  t1 = l1;
  t1->next = new ListNode(4);
  t1 = t1->next;
  t1->next = new ListNode(3);
   
  ListNode* l2 = new ListNode(5);
  t1 = l2;
  t1->next = new ListNode(6);
  t1 = t1->next;
  t1->next = new ListNode(9);
  t1 = t1->next;
  t1->next = new ListNode(9);

  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);
  while (result != NULL) {
    cout << result->val << "\n";
    result = result->next;
  }
}
