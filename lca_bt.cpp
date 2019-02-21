#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    bool p_found = false;
    bool q_found = false;
    int max_depth = 0;
    TreeNode *lca = root;

    lcaHelper(root, p, q, p_found, q_found, 0, max_depth, lca);

    return lca;
  }

  void lcaHelper(TreeNode *root, TreeNode *p, TreeNode *q, bool &p_found,
    bool &q_found, int curr_depth, int &max_depth, TreeNode* &lca) {
    if (root == nullptr) {
      return;
    }

    bool p_left, p_right, q_left, q_right;
    p_left = p_right = q_left = q_right = false;
    
    lcaHelper(root->left, p, q, p_left, q_left, curr_depth + 1,
      max_depth, lca);
    lcaHelper(root->right, p, q, p_right, q_right, curr_depth + 1,
      max_depth, lca);

    p_found = (root->val == p->val) || p_left || p_right;
    q_found = (root->val == q->val) || q_left || q_right;
    if (p_found && q_found && curr_depth > max_depth) {
      lca = root;
      max_depth = curr_depth;
    }

  }
};

int main(void) {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);

  TreeNode *result = sol.lowestCommonAncestor(root, root->left, root->right);
  cout << result->val << endl;

  result = sol.lowestCommonAncestor(root, root->left, root->left->right->right);
  cout << result->val << endl;

}
