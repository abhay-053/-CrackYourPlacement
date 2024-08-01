class Solution {
public: 
    void helper(vector<int>& nums, int idx, vector<int>& tmp, vector<vector<int>>& ans)
    {
        if(idx == nums.size())
        {
            ans.push_back(tmp);
            return ;
        }

        tmp.push_back(nums[idx]);
        helper(nums,idx+1,tmp,ans);

        tmp.pop_back();
        helper(nums,idx+1,tmp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(nums,0,tmp,ans);
        return ans;
    }
};