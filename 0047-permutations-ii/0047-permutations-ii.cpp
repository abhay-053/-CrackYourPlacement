class Solution {
    private:
    void solve(vector<int> v, set<vector<int> > &ans , vector<int> &nums,vector<int> &vis)
    {
        if(v.size()==nums.size())
        {
            ans.insert(v);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                v.push_back(nums[i]);
                solve(v,ans,nums,vis);
                v.pop_back();
                vis[i]=0;
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int> > ans;
        vector<int> v;
        vector<int> vis(nums.size(),0);
        solve(v,ans,nums,vis);
        for(auto i: ans)
            res.push_back(i);
        return res;
    }
};