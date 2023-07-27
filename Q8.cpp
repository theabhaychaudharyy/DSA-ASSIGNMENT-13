#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of the tree.
int calculateHeight(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    return 1 + std::max(calculateHeight(root->left), calculateHeight(root->right));
}

// Function to populate the matrix using a recursive approach.
void populateMatrix(TreeNode* root, std::vector<std::vector<std::string>>& matrix, int r, int c, int height) {
    if (root == nullptr) {
        return;
    }

    matrix[r][c] = std::to_string(root->val);

    int offset = (1 << (height - r - 1)) - 1;
    populateMatrix(root->left, matrix, r + 1, c - offset, height);
    populateMatrix(root->right, matrix, r + 1, c + offset, height);
}

std::vector<std::vector<std::string>> formatTreeLayout(TreeNode* root) {
    int height = calculateHeight(root);
    int rows = height + 1;
    int cols = (1 << (height + 1)) - 1;

    std::vector<std::vector<std::string>> matrix(rows, std::vector<std::string>(cols, ""));

    int center = cols / 2;
    populateMatrix(root, matrix, 0, center, height);

    return matrix;
}

int main() {
    // Example: [1,2,3,4,5,6,7]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<std::string>> result = formatTreeLayout(root);

    // Printing the matrix for verification.
    for (const auto& row : result) {
        for (const std::string& val : row) {
            std::cout << (val.empty() ? " " : val) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
