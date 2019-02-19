#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <functional>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<uintptr_t, uintptr_t> pointer_map;
    return copyHelper(head, pointer_map);
  }

  RandomListNode *copyHelper(RandomListNode *head, 
    unordered_map<uintptr_t, uintptr_t> &pointer_map) {
    if (head == nullptr) {
      return head;
    }

    if (pointer_map.find(reinterpret_cast<uintptr_t>(head)) != pointer_map.end()) {
      return reinterpret_cast<RandomListNode*>(pointer_map[reinterpret_cast<uintptr_t>(head)]);
    }

    RandomListNode *head_copy = new RandomListNode(head->label);
    pointer_map[reinterpret_cast<uintptr_t>(head)] = reinterpret_cast<uintptr_t>(head_copy);
    head_copy->next = copyHelper(head->next, pointer_map);
    head_copy->random = copyHelper(head->random, pointer_map);

    return head_copy;

  }
};

int main(void) {
  Solution sol;
  RandomListNode *r1 = nullptr;
  cout << (sol.copyRandomList(r1) == nullptr) << endl;

  r1 = new RandomListNode(2);
  r1->next = new RandomListNode(3);
  r1->random = new RandomListNode(4);
  r1->next->next = new RandomListNode(8);
  r1->next->next->next = new RandomListNode(7);
  r1->next->next->random = r1->next;

  RandomListNode *r2 = sol.copyRandomList(r1);
  cout << r2->label << " ";
  cout << r2->next->label << " ";
  cout << r2->random->label << " " << endl;

  cout << r2->next->label << " ";
  cout << r2->next->next->label << " ";
  cout << (r2->next->random == nullptr) << " " << endl;

  cout << r2->next->next->label << " ";
  cout << r2->next->next->next->label << " ";
  cout << r2->next->next->random->label << " " << endl;
  

}
