#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root, int& diameter) {
    if (root == nullptr) return 0;

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    diameter = std::max(diameter, leftHeight + rightHeight);
    return 1 + std::max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Example 1: [1,2,3,4,5]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    int result1 = diameterOfBinaryTree(root1);
    std::cout << "Output for Example 1: " << result1 << std::endl;

    // Example 2: [1,2]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    int result2 = diameterOfBinaryTree(root2);
    std::cout << "Output for Example 2: " << result2 << std::endl;

    return 0;
}
