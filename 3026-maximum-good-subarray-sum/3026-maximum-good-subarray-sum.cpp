class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<long long, long long> mp;
        long long ans = -1e15;
        mp[nums[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (mp.count(nums[i] - k)) {
                ans = max(ans, prefix[i] - mp[nums[i] - k]);
            }

            if (mp.count(nums[i] + k)) {
                ans = max(ans, prefix[i] - mp[nums[i] + k]);
            }

            long long before = prefix[i - 1];

            if (!mp.count(nums[i])) {
                mp[nums[i]] = before;
            } else {
                mp[nums[i]] = min(mp[nums[i]], before);
            }
        }

        return ans == -1e15 ? 0 : ans;
    }
};