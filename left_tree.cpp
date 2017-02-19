#include <cstddef>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  static int findBottomLeftValue(TreeNode *root) {
    int *level;
    level = new int;
    *level = 0;
    return findBottomLeftSubTree(root, level);
  }

  static int findBottomLeftSubTree(TreeNode *root, int *level) {
    int *level_l;
    int *level_r;
    int left_val;
    int right_val;

    // Base case, no children.
    if ((root->left == NULL) && (root->right == NULL)) {
      return root->val;
    }
  
    // Only left child.
    else if ((root->left != NULL) && (root->right == NULL)) {
      *level = *level + 1;
      return findBottomLeftSubTree(root->left, level);
    }

    // Only right child.
    else if ((root->left == NULL) && (root->right != NULL)) {
      *level = *level + 1;
      return findBottomLeftSubTree(root->right, level);
    }

    // Both children exist.
    else {
      level_l = new int;
      level_r = new int;

      *level_l = (*level) + 1;
      *level_r = (*level) + 1;
      
      left_val = findBottomLeftSubTree(root->left, level_l);
      right_val = findBottomLeftSubTree(root->right, level_r);
      
      // Compare the levels.
      if (*level_r > *level_l) {
        *level = *level_r;
        delete level_r;
        return right_val;
      }
      else {
        *level = *level_l;
        delete level_l;
        return left_val;
      }
    }
  }
};

int main(void) {
  TreeNode tree = TreeNode(2);
  TreeNode left_tree = TreeNode(1);
  TreeNode right_tree = TreeNode(3);
  tree.left = &left_tree;
  tree.right = &right_tree;  
  int val = Solution::findBottomLeftValue(&tree);
  std::cout << val;

  return 0;
}
