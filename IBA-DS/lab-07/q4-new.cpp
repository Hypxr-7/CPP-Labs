#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequentElements(vector<int>& nums, int k) {
    // Count the frequency of each element
    unordered_map<int, int> frequency;
    for (int num : nums) {
        frequency[num]++;
    }
    
    // Use a max-priority queue
    priority_queue<pair<int, int>> maxHeap;
    for (auto& [num, freq] : frequency) {
        maxHeap.push({freq, num});
    }
    
    // Extract the top K elements
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequentElements(nums, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}