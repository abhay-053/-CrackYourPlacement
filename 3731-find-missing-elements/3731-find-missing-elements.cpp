class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> ans;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[i-1] + 1){
                for(int j = nums[i-1] + 1; j <= nums[i] - 1; j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};