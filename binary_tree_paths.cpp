#include <iostream>
#include <string>
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    if (root == nullptr) {
      return paths;
    }

    string curr_path;
    pathHelper(root, paths, curr_path);

    return paths;
  }

  void pathHelper(TreeNode *root, vector<string> &paths, string curr_path) {
    if (curr_path.size() == 0) {
      curr_path += to_string(root->val);
    }
    else {
      curr_path += "->";
      curr_path += to_string(root->val);
    }

    if (root->left == nullptr && root->right == nullptr) {
      paths.push_back(curr_path);
    }
    if (root->left != nullptr) {
      pathHelper(root->left, paths, curr_path);
    }
    if (root->right != nullptr) {
      pathHelper(root->right, paths, curr_path);
    }
  }
};

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  Solution sol;
  for (string s : sol.binaryTreePaths(root)) {
    cout << s << endl;
  }
}
