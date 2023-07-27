#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - k;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    std::vector<int> result(arr.begin() + left, arr.begin() + left + k);
    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 4;
    int x1 = 3;
    std::vector<int> result1 = findClosestElements(arr1, k1, x1);
    
    std::cout << "Output for Example 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 4;
    int x2 = -1;
    std::vector<int> result2 = findClosestElements(arr2, k2, x2);
    
    std::cout << "Output for Example 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
