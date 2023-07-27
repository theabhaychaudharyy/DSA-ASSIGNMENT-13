#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (leftSubtree == nullptr && rightSubtree == nullptr) {
        return true;
    }

    if (leftSubtree == nullptr || rightSubtree == nullptr) {
        return false;
    }

    return (leftSubtree->val == rightSubtree->val) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    return isMirror(root->left, root->right);
}

int main() {
    // Example: [1,2,2,3,4,4,3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);
    std::cout << "Output for the example: " << std::boolalpha << result << std::endl;

    return 0;
}
