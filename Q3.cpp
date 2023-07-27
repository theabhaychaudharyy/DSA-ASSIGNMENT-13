#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool compareWords(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first; // Sort lexicographically if frequencies are the same.
    } else {
        return a.second > b.second; // Sort by frequency in descending order.
    }
}

std::vector<std::string> kMostFrequentWords(const std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> wordFrequency;
    for (const std::string& word : words) {
        wordFrequency[word]++;
    }

    std::vector<std::pair<std::string, int>> sortedWords;
    for (const auto& pair : wordFrequency) {
        sortedWords.push_back(pair);
    }

    std::sort(sortedWords.begin(), sortedWords.end(), compareWords);

    std::vector<std::string> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(sortedWords[i].first);
    }

    return result;
}

int main() {
    std::vector<std::string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    int k1 = 2;
    std::vector<std::string> result1 = kMostFrequentWords(words1, k1);
    std::cout << "Output for Example 1: ";
    for (const std::string& word : result1) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k2 = 4;
    std::vector<std::string> result2 = kMostFrequentWords(words2, k2);
    std::cout << "Output for Example 2: ";
    for (const std::string& word : result2) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
