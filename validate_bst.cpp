#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) {
      return true;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    return bstHelper(root, min, max);

  }

  bool bstHelper(TreeNode *root, int &min, int &max) {
    if (root->left && root->right) {
      int lmin, lmax, rmin, rmax;
      lmin = rmin = INT_MAX;
      lmax = rmax = INT_MIN;
      bool left_valid = bstHelper(root->left, lmin, lmax);
      bool right_valid = bstHelper(root->right, rmin, rmax);

      if (!left_valid || !right_valid || lmax >= root->val 
          || rmin <= root->val) {
        return false;
      }

      min = lmin;
      max = rmax;
      return true;
    }
    else if (root->left) {
      int lmin, lmax;
      lmin = INT_MAX;
      lmax = INT_MAX;
      bool left_valid = bstHelper(root->left, lmin, lmax);
      if (!left_valid || lmax >= root->val) {
        return false;
      }

      min = lmin;
      max = root->val;
      return true;
    }
    else if (root->right) {
      int rmin, rmax;
      rmin = INT_MAX;
      rmax = INT_MIN;
      bool right_valid = bstHelper(root->right, rmin, rmax);
      if (!right_valid || rmin <= root->val) {
        return false;
      }

      min = root->val;
      max = rmax;
      return true;
    }
    else {
      min = root->val;
      max = root->val;
      return true;
    }
  }
};

int main(void) {
  Solution sol;
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  cout << sol.isValidBST(root) << "\n";

  root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(6);

  cout << sol.isValidBST(root) << "\n";

}
