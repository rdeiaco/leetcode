#include <queue>
#include <vector>
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
  std::vector<int> largestValues(TreeNode *root) {
    std::vector<int> largest;
    std::queue<int> layers;
    std::queue<TreeNode*> nodes;

    if (!root) {
      return largest;
    }

    largestValues_helper(root, 0, largest, layers, nodes);
    return largest;
  }

  void largestValues_helper(TreeNode *root, int layer, std::vector<int> &largest,
    std::queue<int> &layers, std::queue<TreeNode*> &nodes) {
   
    int val = root->val;  

    // Check to see if we have any values in the vector that correspond to this layer yet.
    // If not, add that value to the corresponding location in the vector.
    if (largest.size() == layer) {
     largest.push_back(val);
    }

    // Otherwise, check if this value is greater than the one currently at this layer.
    else if (val > largest[layer]) {
      largest[layer] = val;
    }

    // Push the children onto the queues to perform DFS.
    if (root->left) {
      layers.push(layer + 1);
      nodes.push(root->left);
    }

    if (root->right) {
      layers.push(layer + 1);
      nodes.push(root->right);
    }
    
    // Check to see if there are any children to process.
    if (nodes.empty()) {
      return;
    }
    else {
      TreeNode *next_node = nodes.front();
      int next_layer = layers.front();
      nodes.pop();
      layers.pop();
      largestValues_helper(next_node, next_layer, largest, layers, nodes);
    }
  }
};

int main(void) {
  TreeNode root = TreeNode(1);
  TreeNode temp1 = TreeNode(3);
  TreeNode temp2 = TreeNode(2);
  TreeNode temp3 = TreeNode(5);
  TreeNode temp4 = TreeNode(3);
  TreeNode temp5 = TreeNode(9);

  root.left = &temp1;
  root.right = &temp2;
  root.left->left = &temp3;
  root.left->right = &temp4;
  root.right->right = &temp5;
  
  Solution sol;
  std::vector<int> results = sol.largestValues(&root);
  for (std::vector<int>::iterator it = results.begin(); it != results.end(); it++) {
    std::cout << *it << '\n';
  }
}
