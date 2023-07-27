#include <iostream>
#include <vector>

int countSmallerOrEqual(const std::vector<std::vector<int>>& matrix, int target) {
    int count = 0;
    int n = matrix.size();
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= target) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countSmallerOrEqual(matrix, mid);

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    std::vector<std::vector<int>> matrix1 = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k1 = 8;
    int result1 = kthSmallest(matrix1, k1);
    std::cout << "Output for Example 1: " << result1 << std::endl;

    std::vector<std::vector<int>> matrix2 = {{-5}};
    int k2 = 1;
    int result2 = kthSmallest(matrix2, k2);
    std::cout << "Output for Example 2: " << result2 << std::endl;

    return 0;
}
