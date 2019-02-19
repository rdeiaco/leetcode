#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> right_list;
      int blocked_depth = 0;
      int current_depth = 1;

      if (root == nullptr) {
        return right_list;
      }
      rightSideHelper(root, right_list, current_depth, blocked_depth);

      return right_list;
    }

    void rightSideHelper(TreeNode *root, vector<int> &right_list,
      int current_depth, int &blocked_depth) {
      if (blocked_depth < current_depth) {
        right_list.push_back(root->val);
        blocked_depth++;
      }

      if (root->right != nullptr) {
        rightSideHelper(root->right, right_list, current_depth + 1,
          blocked_depth);
        if (root->left != nullptr) {
          rightSideHelper(root->left, right_list, current_depth + 1,
            blocked_depth);
        }
      }
      else if (root->left != nullptr) {
        rightSideHelper(root->left, right_list, current_depth + 1,
          blocked_depth);
      }

    }
};

int main(void) {
  Solution sol;
  TreeNode *bst = new TreeNode(1);
  bst->left = new TreeNode(2);
  bst->right = new TreeNode(3);
  bst->left->right = new TreeNode(5);
  bst->right->right = new TreeNode(4);
  bst->left->right->left = new TreeNode(8);

  vector<int> result = sol.rightSideView(bst);
  for (int i : result) {
    cout << i << endl;
  }
}
