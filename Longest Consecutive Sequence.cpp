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
