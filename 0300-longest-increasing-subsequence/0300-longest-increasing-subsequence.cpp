class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(int num: nums){
            int val = lower_bound(begin(ans), end(ans), num) - begin(ans);

            if(val == ans.size()){
                ans.push_back(num);
            } else {
                ans[val] = num;
            }
        }
        return ans.size();
    }
};