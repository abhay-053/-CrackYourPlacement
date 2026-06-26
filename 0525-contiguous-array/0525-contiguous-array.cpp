class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int curSum = 0;
        int maxLen = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                curSum += 1;
            } else {
                curSum += -1;
            }

            
            if(mp.find(curSum) == mp.end() ){
                mp[curSum] = i;
            } else {
                maxLen = max(maxLen, i - mp[curSum]);
            }
        }

        return maxLen;
    }
};