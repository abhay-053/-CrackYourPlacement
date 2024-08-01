class Solution {
public: 
    void solve(int idx, vector<int> v, set<vector<int>> &ans, vector<int> &nums)
    {
        ans.insert(v);
        for(int i=idx;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            solve(i+1,v,ans,nums);
            v.pop_back();
        }
    } 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(0, v,ans,nums);
        for(auto i: ans)
        {
            res.push_back(i);
        }
        return res;
    }
};