class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int val = nums[i];
            mp[val]++;
            while( l< n && mp[val] > k){
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};