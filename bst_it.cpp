#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    while (root != nullptr) {
      node_stack.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *temp = node_stack.top();
    node_stack.pop();
    int val = temp->val;
    temp = temp->right;
    while (temp != nullptr) {
      node_stack.push(temp);
      temp = temp->left;
    }
    
  
    return val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !node_stack.empty();
  }
  
  stack<TreeNode *> node_stack;


};

int main(void) {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);
  root->right->left->right = new TreeNode(11);

  BSTIterator iterator = BSTIterator(root);
  cout << iterator.next() << endl;
  cout << iterator.next() << endl;
  if (iterator.hasNext()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  cout << iterator.next() << endl;
  if (iterator.hasNext()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  cout << iterator.next() << endl;
  if (iterator.hasNext()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  cout << iterator.next() << endl;
  if (iterator.hasNext()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  cout << iterator.next() << endl;
  if (iterator.hasNext()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }

}
