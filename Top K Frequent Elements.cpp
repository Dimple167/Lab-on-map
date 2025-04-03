class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> frequencyList; // (count, number)
        int currentCount = 1;
        
        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == nums[i - 1]) {
                currentCount++;
            } else {
                frequencyList.push_back({currentCount, nums[i - 1]});
                currentCount = 1; // Reset count for the next number
            }
        }

        sort(frequencyList.begin(), frequencyList.end(), greater<>());

        
        vector<int> topKElements;
        for (int i = 0; i < k; i++) {
            topKElements.push_back(frequencyList[i].second);
        }

        return topKElements;
    }
};
