class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int curSum = 0; 
        int validLeftPoints = 0;
        long long ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i< n; i++){

            if(nums[i] == target){
                validLeftPoints += mp[curSum];
                curSum += 1;
            } else {
                curSum -= 1;
                validLeftPoints -= mp[curSum];
            }

            mp[curSum] += 1;
            ans += validLeftPoints;

        }

        

        return ans;
    }
};
