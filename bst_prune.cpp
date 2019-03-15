#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) { 
    pruneHelper(root);
    return root;
  }

  bool pruneHelper(TreeNode *root) {
    if (root == NULL) {
      return false;
    }
    else {
      bool left_valid = pruneHelper(root->left);
      bool right_valid = pruneHelper(root->right);

      if (!left_valid) {
        root->left = NULL;
      }
      if (!right_valid) {
        root->right = NULL;
      }

      return left_valid || right_valid || root->val == 1;
    }
  }
};

int main(void) {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(0);

  sol.pruneTree(root);

  cout << (root->val == 1) << endl;
  cout << (root->right->val == 1) << endl;
  cout << (root->left == NULL) << endl;
  cout << (root->right->left == NULL) << endl;
  cout << (root->right->right->val == 1) << endl;
}
