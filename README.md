# LeetCode Submissions

## 1. Valid Sudoku  
**Submission Link:** [Click Here](http://leetcode.com/problems/valid-sudoku/submissions/1595862031/)  
```cpp
    class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';  // Convert '1'-'9' to 0-8
                    int boxIndex = (r / 3) * 3 + (c / 3);

                    if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                        return false;  // Duplicate found
                    }

                    rows[r][num] = cols[c][num] = boxes[boxIndex][num] = 1;
                }
            }
        }
        
        return true;
    }
};

```

## 2. Top K Frequent Elements  
**Submission Link:** [Click Here](http://leetcode.com/problems/top-k-frequent-elements/submissions/1595861704/)  
```cpp
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
```

## 3. First Unique Character in a String  
**Submission Link:** [Click Here](https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1594468399/)  
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for(char ch : s){
            freq[ch - 'a']++;
        }

        for(int i = 0 ; i < s.length() ; i++ ){
            if(freq[s[i] - 'a'] == 1 ){
               return i; 
            }
        }
        
        return -1; 
    }
};

```

## 4. Longest Consecutive Sequence  
**Submission Link:** [Click Here](https://leetcode.com/problems/longest-consecutive-sequence/?source=submission-ac)  
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if(num.empty())       return 0;
        sort(num.begin() , num.end());
        int longest=1,current=1;
        for(int i =1 ;i <num.size() ; i++){
            if(num[i] == num[i-1])  continue;
            if(num[i] == num[i-1] + 1)  current++;
            else{
                longest = max( longest,current);
                current=1;
            }
        }

        return max(longest,current);
    }
};
```

## 5. Two Sum  
**Submission Link:** [Click Here](https://leetcode.com/problems/two-sum/submissions/1595866038/)  
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int x=0;x<n-1;x++){
            for(int y=x+1;y<n;y++){
                if(nums[x]+nums[y]==target){
                    return {x,y};
                }
            }
        }
        return {};
    }
};
```

---

