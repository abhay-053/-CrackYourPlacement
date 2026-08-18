class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size() == k){
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int ans = -1;
        if(k==1){
            for(auto i:mp){
                if(i.second == 1){
                    ans = max(ans,i.first);
                }
            }
            return ans;
        }
        if(mp[nums[0]]==1 && mp[nums[nums.size()-1]]==1)
            ans = max(nums[0], nums[nums.size()-1]);
        else if(mp[nums[0]]==1 && mp[nums[nums.size()-1]]>1)
            ans = nums[0];
        else if(mp[nums[0]]>1 && mp[nums[nums.size()-1]]==1)
            ans = nums[nums.size()-1];
        return ans;
    }
};