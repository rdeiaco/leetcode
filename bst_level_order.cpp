#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    levelOrderHelper(root, result, 0);

    return result;
  }

  void levelOrderHelper(TreeNode *root, vector<vector<int>> &result, int depth) {
    if (root == nullptr) {
      return;
    }

    if (depth == result.size()) {
      vector<int> row;
      row.push_back(root->val);
      result.push_back(row);
    }
    else {
      result[depth].push_back(root->val);
    }

    levelOrderHelper(root->left, result, depth + 1);
    levelOrderHelper(root->right, result, depth + 1);

  }
};

int main(void) {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->left->left = new TreeNode(5);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> result = sol.levelOrder(root);

  for (auto row : result) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}
