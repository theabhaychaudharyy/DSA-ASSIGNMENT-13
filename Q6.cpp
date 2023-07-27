#include <iostream>
#include <vector>
#include <algorithm>

bool compareStrings(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) {
        return a > b; // Compare as strings if lengths are the same.
    } else {
        return a.length() > b.length(); // Compare by length in descending order.
    }
}

std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
    std::sort(nums.begin(), nums.end(), compareStrings);
    return nums[k - 1]; // k is 1-indexed, but the vector is 0-indexed.
}

int main() {
    std::vector<std::string> nums1 = {"3", "6", "7", "10"};
    int k1 = 2;
    std::string result1 = kthLargestNumber(nums1, k1);
    std::cout << "Output for Example 1: " << result1 << std::endl;

    std::vector<std::string> nums2 = {"3", "6", "7", "10"};
    int k2 = 3;
    std::string result2 = kthLargestNumber(nums2, k2);
    std::cout << "Output for Example 2: " << result2 << std::endl;

    std::vector<std::string> nums3 = {"1", "2", "2"};
    int k3 = 2;
    std::string result3 = kthLargestNumber(nums3, k3);
    std::cout << "Output for Example 3: " << result3 << std::endl;

    return 0;
}
