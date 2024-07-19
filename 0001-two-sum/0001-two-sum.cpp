class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            int val = target-nums[i];
            if(mp.find(val) != mp.end())
            {
                return {i,mp[val]};
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};